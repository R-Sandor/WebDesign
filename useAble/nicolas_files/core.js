var hasTouch = !1, mc, n, r, $homepage;
$(document).on("mousemove", function(a) {
  n = a.pageX + 11, r = a.pageY + 11
}), "ontouchstart"in document.documentElement && (document.documentElement.className += " touch", hasTouch = !0), (!Modernizr.fontface || navigator.userAgent.match(/(Android (2.0|2.1))|(Nokia)|(Opera (Mini|Mobi))|(w(eb)?OSBrowser)|(UCWEB)|(Windows Phone)|(XBLWP)|(ZuneWP)/)) && (document.documentElement.className += " nofontface");
var Core = {construct: function() {
    Core.$_wrapper = $("div#wrapper"), Core.$_home = $("div#app #projects"), Core.$boolean = !0, $("#diamond").JSMovieclip({width: 61, direction: "h", frames_number: 4, framerate: 10}), mc = $("#diamond").data("JSMovieclip"), Core.$_wrapper.on({click: function(a) {
        a.preventDefault(), Core.mouseAnimation(0, 0)
      }}, ".square"), Core.$_wrapper.on({click: function(a) {
        a.preventDefault(), $("html, body").animate({scrollTop: 0}, 1e3)
      }}, "a.go-top")
  }, init: function() {
    hasTouch || CoreClients.init(), $(".link-popin").on("click", function() {
      return Popup.init("data1"), !1
    }), $(document).on({click: function(a) {
        return a.preventDefault(), Popup.quit(), !1
      }}, "div.popin div.close"), $("#stickynav #details").mouseenter(function() {
      $(this).addClass("active")
    }), $("#stickynav #details").mouseleave(function() {
      $(this).removeClass("active")
    }), $("#header li").mouseenter(function() {
      TweenLite.to($(this).children("a"), .1, {css: {color: "#FFF"}, ease: Strong.easeOut}), TweenLite.to($(this), .3, {css: {backgroundPosition: "0 -80px"}, ease: Strong.easeOut}), Core.soundNotif($(this))
    }), $("#header li").mouseleave(function() {
      TweenLite.to($(this).children("a"), .1, {css: {color: "#ABABAB"}, ease: Strong.easeOut}), TweenLite.to($(this), .1, {css: {backgroundPosition: "0 0px"}, ease: Strong.easeOut})
    })
  }, soundNotif: function(a) {
    a.children(".sound_player")[0].play()
  },
  mouseAnimation:function(a,b){$("#waves").css({left:n-a,top:r-b}).show(),$("#waves > div").eq(0).addClass("go");var c=setTimeout(function(){$("#waves > div").eq(1).addClass("go");var a=setTimeout(function(){$("#waves").hide().children().removeClass("go"),clearTimeout(c),clearTimeout(a)},1e3)},200)},
  scripts: function(a) {
    switch (top.imagesArray = Array(), a) {
      case"salomon":
        imagesArray = ["../img/works/salomon/imac.jpg", "../img/works/salomon/ipad-intro.png", "../img/works/salomon/bubble-1.png", "../img/works/salomon/bubble-2.png", "../img/works/salomon/bubble-3.png","../img/works/salomon/preview-2.jpg","../img/works/salomon/preview-3.jpg","../img/works/salomon/preview-4.jpg","../img/works/salomon/preview-5.jpg" ];
        break;
      case"withings":
        imagesArray = ["../img/works/withings/preview-1.jpg","../img/works/withings/preview-2.jpg","../img/works/withings/preview-3.jpg","../img/works/withings/preview-4.jpg","../img/works/withings/preview-5.jpg" ];
        break;
      case"warner-godzilla":
        imagesArray = ["../img/works/warner-godzilla/preview-1.jpg","../img/works/warner-godzilla/preview-2.jpg","../img/works/warner-godzilla/preview-3.jpg" ];
        break;
      case"forwards":
        imagesArray = ["../img/works/forwards/preview-1.jpg","../img/works/forwards/preview-2.jpg","../img/works/forwards/preview-3.jpg" ];
        break;
      case"martini":
        imagesArray = ["../img/works/martini/verre.png", "../img/works/martini/imac.png", "../img/works/martini/screen-1.jpg"];
        break;
      case"tignes":
        imagesArray = ["../img/works/tignes/iphone-1.png", "../img/works/tignes/iphone-2.png", "../img/works/tignes/iphone-3.png", "../img/works/tignes/ipad-centre.png", "../img/works/tignes/ipad-left.jpg", "../img/works/tignes/ipad-right.jpg"];
        break;
      case"fdj":
        imagesArray = ["../img/works/fdj/slide1.png", "../img/works/fdj/slide2.png", "../img/works/fdj/slide3.png", "../img/works/fdj/slide4.png"];
        break;
      case"crazyhorse":
        imagesArray = ["../img/works/crazyhorse/imac.jpg"];
        break;
      case"mobalpa":
        imagesArray = ["../img/works/mobalpa/macbook.png", "../img/works/mobalpa/slide1.png", "../img/works/mobalpa/slide2.png", "../img/works/mobalpa/slide3.png", "../img/works/mobalpa/slide4.png"];
        break;
      case"reebok":
        imagesArray = ["../img/works/reebok/imac.jpg", "../img/works/reebok/ipad-intro.png", "../img/works/reebok/bubble-1.png", "../img/works/reebok/bubble-2.png", "../img/works/reebok/bubble-3.png", "../img/works/reebok/preview-2.jpg", "../img/works/reebok/preview-3.jpg", "../img/works/reebok/preview-4.jpg", "../img/works/reebok/preview-5.jpg", "../img/works/reebok/mobile-site-2.png", "../img/works/reebok/mobile-site-3.png", "../img/works/reebok/mobile-site-4.png", "../img/works/reebok/mobile-site-5.png", "../img/works/reebok/iphone1.png", "../img/works/reebok/iphone2.png", "../img/works/reebok/iphone3.png"];
        break;
      case"lacoste-future":
        imagesArray = ["../img/works/lacoste-future/loader.gif", "../img/works/lacoste-future/ipad-intro-screen.png", "../img/works/lacoste-future/preview-1.jpg", "../img/works/lacoste-future/preview-2.jpg", "../img/works/lacoste-future/preview-3.jpg", "../img/works/lacoste-future/preview-4.jpg"];
        break;
      case"boucheron":
        imagesArray = ["../img/works/boucheron/ipad-intro.png", "../img/works/boucheron/preview-1.jpg", "../img/works/boucheron/preview-2.jpg", "../img/works/boucheron/preview-3.jpg", "../img/works/boucheron/preview-4.jpg", "../img/works/boucheron/preview-5.jpg"];
        break;
      case"warner-the-hobbit":
        imagesArray = ["../img/works/warner-the-hobbit/map-video.jpg", "../img/works/warner-the-hobbit/slide1.png", "../img/works/warner-the-hobbit/slide2.png", "../img/works/warner-the-hobbit/slide3.png", "../img/works/warner-the-hobbit/slide4.png", "../img/works/warner-the-hobbit/cadre.png", "../img/works/warner-the-hobbit/map.jpg"];
        break;
      case"orange-euro2012":
        imagesArray = ["../img/works/orange-euro2012/preview-1.jpg", "../img/works/orange-euro2012/preview-2.jpg", "../img/works/orange-euro2012/preview-3.jpg", "../img/works/orange-euro2012/preview-4.jpg", "../img/works/orange-euro2012/preview-5.jpg", "../img/works/orange-euro2012/ipad1-circle.png", "../img/works/orange-euro2012/ipad2-circle.png", "../img/works/orange-euro2012/ipad3-circle.png", "../img/works/orange-euro2012/ipad4-circle.png"];
        break;
      case"lacoste-tennis":
        imagesArray = ["../img/works/lacoste-tennis/ipad1.jpg", "../img/works/lacoste-tennis/ipad2.jpg", "../img/works/lacoste-tennis/ipad3.jpg", "../img/works/lacoste-tennis/ipad4.jpg"];
        break;
      case"lequipe":
        imagesArray = ["../img/works/lequipe/ipad1.jpg", "../img/works/lequipe/ipad2.jpg"];
        break;
      case"lacoste-fashion-show":
        imagesArray = ["../img/works/lacoste-fashion-show/screen.jpg"];
        break;
      case"warner-contagion":
        imagesArray = ["../img/works/warner-contagion/dvd.jpg", "../img/works/warner-contagion/ipad1.jpg", "../img/works/warner-contagion/ipad2.jpg"];
        break;
      case"de-mains-en-mains":
        imagesArray = ["../img/works/de-mains-en-mains/iphone1.png", "../img/works/de-mains-en-mains/iphone2.png"];
        break;
      case"the-front-face":
        imagesArray = ["../img/works/the-front-face/ipad1.png"];
        break;
      case"trick-or-treat":
        imagesArray = ["../img/trick-or-treat/iphone1.png", "../img/trick-or-treat/iphone2.png", "../img/trick-or-treat/iphone3.png", "../img/trick-or-treat/iphone4.png"];
        break;
      case"monster-run":
        imagesArray = ["../img/works/monster-run/ipad-intro.jpg", "../img/works/monster-run/slide1.jpg", "../img/works/monster-run/slide2.jpg", "../img/works/monster-run/slide3.jpg"];
        break;
      case"mother-mountain":
        imagesArray = ["../img/works/mother-mountain/imac.jpg", "../img/works/mother-mountain/ipad1.jpg", "../img/works/mother-mountain/ipad2.jpg", "../img/works/mother-mountain/ipad3.jpg", "../img/works/mother-mountain/ipad4.jpg", "../img/works/mother-mountain/ipad5.jpg"];
        break;
      case"jean-claude-di-ruocco":
        imagesArray = ["../img/works/jean-claude-di-ruocco/ipad1.jpg", "../img/works/jean-claude-di-ruocco/ipad2.jpg", "../img/works/jean-claude-di-ruocco/ipad3.jpg"];
        break;
      case"embed":
        imagesArray = ["../img/works/embed/ipad1.jpg"];
        break;
      case"deus-ex":
        imagesArray = ["../img/works/deus-ex/ipad1.jpg", "../img/works/deus-ex/ipad2.jpg", "../img/works/deus-ex/ipad3.jpg", "../img/works/deus-ex/ipad4.jpg", "../img/works/deus-ex/ipad5.jpg"];
        break;
      case"home":
        imagesArray = ["../img/common/mountains.jpg", "../img/home/loading/line.png", "../img/home/loading/left.png", "../img/home/loading/right.png", "../img/home/loading/nicolas.png", "../img/home/loading/borreil.png", "../img/works/deus-ex/logo.png", "../img/works/embed/logo.png", "../img/works/jean-claude-di-ruocco/logo.png", "../img/works/mother-mountain/logo.png", "../img/works/monster-run/logo.png", "../img/works/trick-or-treat/logo.png", "../img/works/the-front-face/logo.png", "../img/works/de-mains-en-mains/logo.png", "../img/works/warner-contagion/logo.png", "../img/works/lacoste-fashion-show/logo.png", "../img/works/lequipe/logo.png", "../img/works/lacoste-tennis/logo.png", "../img/works/orange-euro2012/logo.png", "../img/works/boucheron/logo.png", "../img/works/lacoste-future/logo.png", "../img/works/tignes/logo.png", "../img/works/martini/logo.png", "../img/works/warner-the-hobbit/logo.png", "../img/works/crazyhorse/logo.png", "../img/works/mobalpa/logo.png", "../img/works/reebok/logo.png"];
        break;
      case"about":
        imagesArray = ["../img/about/img_scroll.png", "../img/about/txt_projects.png", "../img/about/txt_awards.png", "../img/about/txt_clients.png", "../img/about/clients.png", "../img/about/cv-fr.png", "../img/about/cv-en.png", "../img/about/rocket.png"]
      }
  }}, Popup = {isActive: !1, that: $(".popin"), content: "", init: function(a) {
    return this.isActive = !0, $("div#wrapper").before("<div id='mask' style='height:" + jQuery("html").height() + "px'></div>"), this.content += '<div class="close"></div>', this.content += '<div class="popin-container"><div class="content">' + $("." + a).html() + "</div></div>", $.template("popinTemplate", this.content), $.tmpl("popinTemplate", {}).appendTo(".popin"), Popup.center(), Popup.onResize(), this.that.fadeIn("slow"), this.that
  }, onResize: function() {
    $(window).resize(function() {
      Popup.center()
    })
  }, center: function() {
    this.that.css("position", "absolute"), this.that.css("top", Math.max(0, (jQuery(window).height() - this.that.outerHeight()) / 2 + jQuery(window).scrollTop()) + "px"), this.that.css("left", Math.max(0, (jQuery(window).width() - this.that.outerWidth()) / 2 + jQuery(window).scrollLeft()) + "px"), $("html").hasClass("touch") && ($("#mask").css("width", "1024px"), this.that.css("left", Math.max(0, (1024 - this.that.outerWidth()) / 2 + jQuery(window).scrollLeft()) + "px"))
  }, quit: function() {
    this.isActive = !1, this.content = "", $("div#mask").fadeOut().remove(), $("div.popin").fadeOut().empty()
  }}, Loading = {init: function(a, b) {
    mc.play(!0), TweenMax.to($("#loading #square"), .8, {css: {rotationY: "180deg"}, repeat: -1, ease: Power2.easeInOut});
    var c = new TimelineMax;
    c.to($("#stickynav"), .6, {css: {bottom: "0"}, delay: .5, ease: Power2.easeInOut}), c.to($("#header"), .6, {css: {top: "0"}, ease: Power2.easeInOut}, "-=0.6"), c.to($("#loading, #app .overlay"), .1, {css: {autoAlpha: 1}, ease: Power2.easeInOut}), c.to($("#loading"), 1, {css: {autoAlpha: 0}, ease: Power2.easeInOut, onComplete: function() {
        if (mc.stop(), TweenMax.to($("#loading #square"), .01, {css: {rotationY: "0deg"}, ease: Power2.easeInOut}), Core.init(), void 0 != a)
          switch (running = !1, a) {
            case"about":
              window[b].init();
              break;
            case"contact":
              window[b].init(), $("#wrapper").addClass("contact"), setTimeout(function() {
                $("#mask-map, #contact").addClass("open")
              }, 1e3);
              break;
            case"home":
              $homepage = $("#wrapper #projects"), $("#wrapper #projects").length > 0 && ($homepage = new App($homepage)), running = !0, indexPage.init();
              break;
            case"works":
              $("#projects_details .detail").addClass("open"), Works.eventScroll(), window[b].init();
              break;
            case"switch":
              Works.eventScroll(), setTimeout(function() {
                $("#projects_details .detail").addClass("open"), window[b].init()
              }, 500);
              break;
            default:
              window[b].init()
            }
      }})
  }}, Switchproject = {init: function(a, b, c) {
    TweenMax.to($("#wrapper #header"), .5, {css: {top: "-80px"}, ease: Power2.easeInOut}), TweenMax.to($("#stickynav"), .5, {css: {bottom: "-145px"}, ease: Power2.easeInOut}), TweenMax.to($("#wrapper #header header"), .5, {css: {borderColor: "#0FBE7A"}, ease: Power4.easeInOut}), TweenMax.to($("div#details, div#details .wrapper"), .5, {css: {background: "#272B2E"}, ease: Power4.easeInOut}), TweenMax.to($("#mask"), .5, {css: {autoAlpha: .9}, ease: Power2.easeInOut});
    var d = $(window).width();
    $(window).on("resize", function() {
      d = $(window).width()
    });
    var f = (a.data("url"), a), g = a.data("project"), h = parseInt($(document).data("heightRow") / 2), i = a.parent(".row").find(".loading"), j = i.children(".frame");
    j.children(".content-loading").css("width", d + "px");
    var m = (j.find("." + g).show(), j.find(".logo-client").addClass(g), parseInt(f.offset().top - $(window).outerHeight() / 2 + h)), n = $(window).outerHeight() + m + h;
    n > $("#app").height() ? setTimeout(function() {
      $("body").scrollTo(m, {axis: "y", duration: 300, onAfter: function() {
          i.css({display: "block"}, 1e3), j.css({background: b}, 1e3), j.animate({width: c + "%"}, 1e3, function() {
            100 == c && i.animate({left: d + "px"}, 600, "easeInOutExpo", function() {
              $("#app").trigger("launchView", ["true"])
            })
          })
        }})
    }, 200) : setTimeout(function() {
      $("body").scrollTo(m, {axis: "y", duration: 300, onAfter: function() {
          i.css({display: "block"}, 1e3), j.css({background: b}, 1e3), j.animate({width: c + "%"}, 1e3, function() {
            100 == c && i.animate({left: d + "px"}, 600, "easeInOutExpo", function() {
              $("#app").trigger("launchView", ["true"])
            })
          })
        }})
    }, 200)
  }, img: function(a) {
    for (var b = 0, c = 0, d = a.length; d > c; c++) {
      var e = new Image;
      e.onload = function() {
        ++b == a.length && console.log("rocket launched !")
      }, e.src = a[c]
    }
  }}, Slider = {create: function() {
    this.$_slider = $("#slider"), this.$_slider.length > 0 && Slider.init()
  }, init: function() {
    $("#slider_nav a").mouseenter(function() {
      $(this).css("background-position", "0 -59px")
    }), $("#slider_nav a").mouseleave(function() {
      $(this).css("background-position", "0 0")
    });
    var a = {width: 600, height: 400, marginLeft: 0, marginTop: 0, marginRight: 0}, b = {width: 400, height: 267, marginLeft: 0, marginTop: 66, marginRight: -300}, c = {width: 400, height: 267, marginLeft: -300, marginTop: 66, marginRight: 0}, d = {width: 150, height: 100, marginLeft: 150, marginTop: 150, marginRight: -200}, e = {width: 150, height: 100, marginLeft: -200, marginTop: 150, marginRight: 50};
    $("#slider").carouFredSel({width: 800, height: 400, align: !1, auto: !1, items: {visible: 3, width: 100}, scroll: {items: 1, duration: 300, onBefore: function(f) {
          "prev" == f.scroll.direction ? (f.items.old.eq(2).animate(e), f.items.visible.eq(2).animate(c), f.items.visible.eq(1).animate(a), f.items.visible.eq(0).animate(b).css({zIndex: 1}), f.items.visible.eq(0).css(d).css({zIndex: 0}), setTimeout(function() {
            f.items.old.eq(2).css({zIndex: 1}), f.items.visible.eq(2).css({zIndex: 2}), f.items.visible.eq(1).css({zIndex: 3}), f.items.visible.eq(0).css({zIndex: 2})
          }, 200)) : (f.items.old.eq(0).animate(d), f.items.visible.eq(0).animate(b), f.items.visible.eq(1).animate(a), f.items.visible.eq(2).animate(c).css({zIndex: 1}), f.items.visible.eq(2).next().css(e).css({zIndex: 0}), setTimeout(function() {
            f.items.old.eq(0).css({zIndex: 1}), f.items.visible.eq(0).css({zIndex: 2}), f.items.visible.eq(1).css({zIndex: 3}), f.items.visible.eq(2).css({zIndex: 2})
          }, 200))
        }}, prev: "#slider_nav .prev", next: "#slider_nav .next"}), $("#slider").children().eq(0).css(b).css({zIndex: 2}), $("#slider").children().eq(1).css(a).css({zIndex: 3}), $("#slider").children().eq(2).css(c).css({zIndex: 2}), $("#slider").children().eq(3).css(e).css({zIndex: 1})
  }}, CoreClients = {init: function() {
    var a;
    Core.$_wrapper.on({mouseenter: function() {
        a = $(this).data("color"), TweenMax.to(this, .5, {css: {borderTop: "3px solid" + a}, ease: Power2.easeInOut})
      }, mouseleave: function() {
        TweenMax.to(this, .5, {css: {borderTop: "3px solid #DFDFDF"}, ease: Power2.easeInOut})
      }}, "div#clients ul li a"), Core.$_wrapper.on({mouseenter: function() {
        var a = $(this).find("span.number");
        TweenMax.to(a, .5, {css: {autoAlpha: 1}, ease: Power2.easeInOut});
        var b = a.children("span"), c = b.data("color");
        b.css("color", c);
        var d = b.data("id"), e = {value: 1};
        TweenMax.to(e, .5, {value: d, roundProps: ["value"], onUpdateParams: ["{self}"], onUpdate: function(a) {
            b.html(a.target.value)
          }})
      }, mouseleave: function() {
        var a = $(this).find("span.number");
        TweenMax.to(a, .5, {css: {autoAlpha: 0}, ease: Power2.easeInOut})
      }}, ".grow"), Core.$_wrapper.on({click: function(a) {
        a.preventDefault();
        var b = new TimelineMax;
        if ($.each($("div#clients ul li a"), function(a, c) {
          var d = $(c).data("color");
          b.to(c, .06, {css: {borderTop: "3px solid" + d}, ease: Power2.easeInOut, onComplete: function() {
              TweenMax.to(c, .4, {css: {borderTop: "3px solid #DFDFDF"}, ease: Power2.easeInOut})
            }})
        }), $(this).hasClass("position")) {
          var c = $(this).data("position");
          $homepage.rowSetCurrent(c), $homepage.scrollToCurr()
        }
      }}, "div#clients ul li a")
  }}, Works = {eventScroll: function() {
    "undefined" != typeof keyPoints && (Works.initAnimations(), Slider.create(), console.log(keyPoints), $("body").off("mousewheel DOMMouseScroll MozMousePixelScroll"), $("body").on("mousewheel DOMMouseScroll MozMousePixelScroll", function(a) {
      var b = $(window).scrollTop(), c = $(document).height(), d = $(window).height(), e = 100 * (b / (c - d));
      Works.checkAnimations(e, a)
    }), Core.$_wrapper.on({mouseenter: function() {
        TweenMax.to($(this), .35, {css: {background: "#272B2E"}, ease: Power4.easeInOut}), TweenMax.to($("#projects_details .share"), .5, {css: {backgroundPosition: "0 -25px", color: "#0FBE7A"}, ease: Power4.easeInOut})
      }, mouseleave: function() {
        TweenMax.to($(this), .35, {css: {background: "#FFF"}, ease: Power4.easeInOut}), TweenMax.to($("#projects_details .share"), .5, {css: {backgroundPosition: "0px 0px", color: "#000"}, ease: Power4.easeInOut})
      }}, "#projects_details .social"), Core.$_wrapper.on({click: function() {
        var a = $(this).data("id"), b = $(this).data("title"), c = "Nicolas Borreil | Portfolio", d = "Interactive & Front-end developer";
        postToFeed(a, b, c, d)
      }}, "#projects_details .social"))
  }, launchAnimation: function(a) {
    var b = keyPoints.animations[a], c = b.selector;
    b.delay > 0 ? setTimeout(function() {
      $(c).transition(b.end, b.duration)
    }, b.delay) : $(c).transition(b.end, b.duration)
  }, initAnimations: function() {
    keyPoints.animationskeyPoints = [], $.support.transition || ($.fn.transition = $.fn.animate);
    var a = keyPoints;
    $.each(keyPoints.animations, function(b, c) {
      a.animationskeyPoints.push({id: b, touchpoint: c.touchpoint}), $(c.selector).css(c.start)
    }), setTimeout(function() {
      Works.checkAnimations(0, 0)
    }, 300)
  }, checkAnimations: function(a) {
    $.each(keyPoints.animationskeyPoints, function(b, c) {
      null == c.played && a >= c.touchpoint && (Works.launchAnimation(c.id), c.played = !0)
    })
  }};
$(document).ready(function() {
  Core.construct(), Core.init(), Loading.init(currentType, currentUrl)
});