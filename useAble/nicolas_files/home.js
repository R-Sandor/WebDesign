var $homepage, running = !0,
    App = function (a) {
        this.$el = a, $.isFunction(this.init) && this.init()
    };
App.prototype = {
    init: function () {
        this.$rows = this.$el.find(".row"), this.$cols = this.$el.find(".col"), this.$elmBig = this.$rows, this.$colwidth = $(window).width(), this.$navTop = $(), this.currentIndex = !1, this.offsetTop = this.$el.offset().top, this.isTouch = Modernizr.touch, this.isSmartphone = this.$el.hasClass("mobile") ? !0 : !1, this.rowsData, this.firstLaunch = !0, this.initNav(), this.initCols(), this.initRows(), this.resize(), this.rowSetCurrent(0), setTimeout($.proxy(function () {
            this.$el.css("visibility", "visible")
        }, this)), $(window).on("resize", $.proxy(this.resize, this)), $(window).on("resize", $.proxy(this.rowHandle, this))
    },
    resize: function () {
      
      var w = $(window).width();
      if(w > 768){ w =  w / 4; }else if(w > 640){ w = w/2; }
      $('.details').css('height',w+'px');

      var a = this.$el.width(),
      b = {
          b: this.isSmartphone === !0 ? 43 : 22,
          s: this.isSmartphone === !0 ? 43 : 15
      };
          
      heightBig = Math.ceil(a * b.b / 100), 
      heightSmall = Math.ceil(a * b.s / 100), 
      this.$elmBig.height(w), 
      //this.$elmSmall.height(heightSmall), 
      $(document).data("heightRow", w), 
      this.isSmartphone && this.$rows.height(2 * w), this.rowsData = [], this.$rows.each($.proxy(function (a, b) {
          var c = $(b),
              a = c.index(),
              d = c.offset().top + c.height() - this.offsetTop;
          this.rowsData.push({
              index: a,
              limit: d
          })
      }, this))
    },
    waitImage: function (a, b) {
        var c = new Image;
        c.onload = function () {
            var e = {
                width: c.width,
                height: c.height
            };
            $.isFunction(b) && b(a, e)
        }, c.onerror = function () {
            $.isFunction(b) && b(!1)
        }, c.src = a
    },
    initNav: function () {
        this.isSmartphone || (this.$navTop = $("#wrapper #header header"), $("div #clients ul li a.start").on("click", $.proxy(this.navPrev, this)), $("div #clients ul li a.end").on("click", $.proxy(this.navNext, this)), this.offsetTop += this.$navTop.outerHeight())
    },
    initRows: function () {
        this.$rows.each($.proxy(function (a, b) {
            var c = $(b),
                d = c.find(".col").first().data("color");
            c.data("color", d)
        }, this))
    },
    initCols: function () {
        this.$cols.each($.proxy(function (a, b) {
            var c = $(b),
                d = $("<div />").addClass("col-body"),
                e = c.find("img.bg");
            if (this.initCol(c), c.data("link")) {
                var f = c.data("link");
                c.find("a").on("click", function (a) {
                    a.stopImmediatePropagation()
                }), c.css({
                    cursor: "pointer"
                }).on("click", function (a) {
                    2 === a.which ? window.open(f, "_blank") : window.location.href = f, c.data("mainLink").triggerHandler("click")
                })
            }
            c.wrapInner(d), e.length && this.initImgBg(e, c), this.$elmBig = this.$elmBig.add(c)
        }, this))
    },
    initCol: function (a) {
        if (a && a.length && a.hasClass("col")) {
            var b = a.data("master") ? ("" + a.data("master")).split(";") : !1;
            if ($row = b ? b.length > 1 ? this.$rows.eq(b[1] - 1) : a.parent(".row") : !1, $master = b !== !1 ? $row.find(".col").eq(b[0] - 1) : a, $mainLink = $master.find(".links a.main").first(), link = $mainLink.attr("href") || !1, color = $master.data("color") || !1, !$master.is(a)) {
                var c = $master.index() < a.index() ? "from-left" : "from-right",
                    d = $("<div />").addClass("hover").addClass(c).css({
                        backgroundColor: color
                    });
                a.append(d), this.isTouch || $master.add(a).on("mouseenter", function () {
                    Modernizr.csstransforms && Modernizr.csstransitions ? d.addClass("show") : d.animate({
                        width: "140%"
                    }, 400)
                }).on("mouseleave", function () {
                    Modernizr.csstransforms && Modernizr.csstransitions ? d.removeClass("show") : d.animate({
                        width: "0%"
                    }, 400)
                })
            }
            a.data("mainLink", $mainLink), a.data("link", link), a.data("color", color), a.css({
                backgroundColor: color
            })
        }
    },
    rowHandle: function () {
        if (this._manualScroll !== !0) {
            var a = $(window).scrollTop();
            $.each(this.rowsData, $.proxy(function (b, c) {
                return a >= c.limit ? (this.rowSetCurrent(c.index + 1), this.firstLaunch = !1, void 0) : 0 === a ? (this.rowSetCurrent(0), void 0) : void 0
            }, this))
        }
    },
    initImgBg: function (a, b) {
        if (a && a.length) {
            var c = a.attr("src"),
                d = $("<span />").addClass("preloader");
            b.append(d), this.waitImage(c, $.proxy(function (c, e) {
                var f = $('<span class="wrap" />');
                a.data("size", e).wrap(f).data("wrapper", f).data("col", b), setTimeout($.proxy(function () {
                    this.imgBgResize(a), $(window).on("resize", $.proxy(function () {
                        this.imgBgResize(a)
                    }, this)), a.fadeIn(200), d.remove()
                }, this))
            }, this))
        }
    },
    imgBgResize: function (a) {
       
    },
    navNext: function () {
        var b = this.currentIndex + 1;
        if (this.firstLaunch) var b = 0;
        this.firstLaunch = !1, this.rowSetCurrent(b), this.scrollToCurr()
    },
    navPrev: function () {
        var b = this.currentIndex - 1;
        this.rowSetCurrent(b), this.scrollToCurr()
    },
    rowSetCurrent: function (a) {
        if (void 0 !== a) {
            var a = a > 0 ? a > this.$rows.length - 1 ? this.$rows.length - 1 : a : 0;
            this.currentIndex = a;
            var c = this.$rows.eq(this.currentIndex);
            0 === this.currentIndex ? "#272B2E" : c.data("color")
        }
    },
    scrollToCurr: function () {
        this._manualScroll = !0;
        var a = this.$rows.eq(this.currentIndex),
            b = a.offset().top - 75;
        $("html, body").stop().animate({
            scrollTop: b
        }, 450, $.proxy(function () {
            this._manualScroll = !1
        }, this))
    }
};
var timer, indexPage = {
        init: function () {
            var a = new TimelineMax;
            a.to($("#preloading .hiddenline"), .5, {
                css: {
                    width: "100%"
                },
                ease: Expo.easeInOut
            }), a.to($("#preloading .loading-left"), .5, {
                css: {
                    left: "50%"
                },
                ease: Expo.easeInOut
            }), a.to($("#preloading .loading-right"), .5, {
                css: {
                    left: "50%"
                },
                ease: Expo.easeInOut
            }, "-=0.5"), a.to($("#preloading .loading-left .nicolas"), .25, {
                css: {
                    autoAlpha: 1
                },
                ease: Expo.easeInOut
            }), a.to($("#preloading .loading-right .borreil"), .25, {
                css: {
                    autoAlpha: 1
                },
                ease: Expo.easeInOut
            }, "-=0.20"), a.to($("#preloading .hiddencontent"), .5, {
                css: {
                    width: "535px",
                    autoAlpha: 1
                },
                ease: Expo.easeInOut
            }), a.to($("#birds"), .1, {
                css: {
                    display: "block"
                },
                ease: Expo.easeInOut
            }), initBirds(), animate(), timer = setTimeout(indexPage.pause, 12e4)
        },
        pause: function () {
            running = !1, $("#birds").hide(), clearTimeout(timer)
        }
    };