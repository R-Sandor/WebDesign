(function(a,b){var f,g,h,i,j,k,l,c=a.History,d=a.jQuery,e=a.document,m=!1;return/msie [1-9]./.test(navigator.userAgent.toLowerCase())&&(m=!0),c.enabled?(d(function(){var n="#app",o=d(n).filter(":first"),p=o.get(0),u=(d("#menu"),"statechangecomplete"),v=d(a),w=d(e.body),x=c.getRootUrl();0===o.length&&(o=w),d.expr[":"].internal=function(a){var h,f=d(a),g=f.attr("href")||"";return h=g.substring(0,x.length)===x||-1===g.indexOf(":")};var z=function(a){var b=(a+"").replace(/<\!DOCTYPE[^>]*>/i,"").replace(/<(html|head|body|title|meta|script)([\s\>])/gi,'<div class="document-$1"$2').replace(/<\/(html|head|body|title|meta|script)\>/gi,"</div>");return d.trim(b)};d.fn.ajaxify=function(){var a=d(this);if(!a.hasClass("no-ajaxy"))return a.find("a:internal:not(.no-ajaxy), .grow").click(function(a){var e=d(this),i=e.attr("href"),j=e.attr("title")||null;if(g=e.data("type"),f=e,i===b&&(i=e.data("url"),h=e.data("color")),2===a.which||a.metaKey)return!0;var k={id:g};return c.pushState(k,j,i),a.preventDefault(),!1}),a},w.ajaxify(),v.on("statechange",function(){function w(c){var q,t,i=d(z(c)),k=i.find(".document-body:first"),l=k.find(n).filter(":first");if(t=l.find(".document-script"),t.length&&t.remove(),q=l.html()||i.html(),!q)return e.location.href=r,!1;e.title=i.find(".document-title:first").text();try{e.getElementsByTagName("title")[0].innerHTML=e.title.replace("<","&lt;").replace(">","&gt;").replace(" & "," &amp; ")}catch(w){}t.each(function(){var a=d(this),b=a.text(),c=e.createElement("script");a.data("src")&&(a[0].async||(c.async=!1),c.src=a.data("src")),c.appendChild(e.createTextNode(b)),p.appendChild(c)});var x=new TimelineMax;"works"===g?(d("#header ul#menu").removeClass("right").addClass("centerPos"),d("#header ul#navWorks").fadeIn()):(d("#projects_details .detail, #mask-map, #contact").removeClass("open"),x.to(d("#wrapper #header"),.5,{css:{top:"-80px"},ease:Power2.easeInOut}),x.to(d("#stickynav"),.5,{css:{bottom:"-145px"},ease:Power2.easeInOut,onComplete:function(){"switch"!==g&&(d("#header ul#menu").removeClass("centerPos").addClass("right"),d("#header ul#navWorks").fadeOut(),d("#menu li").removeClass("current"),d("#menu li."+g).addClass("current"))}},"-=0.5")),x.to(d("#loading"),.5,{css:{autoAlpha:1},ease:Power2.easeInOut}),x.to(d("#app .overlay"),.1,{css:{autoAlpha:0},ease:Power2.easeInOut,onComplete:function(){d("html, body").animate({scrollTop:0},500),d("#wrapper").removeAttr("class").attr("class",""),o.html(q).ajaxify(),"about"===g&&(d("#wrapper").addClass("about"),About.setSize()),Loading.init(g,j)}}),v.trigger(u),a._gaq!==b&&a._gaq.push(["_trackPageview",s]),a.reinvigorate!==b&&a.reinvigorate.ajax_track!==b&&reinvigorate.ajax_track(r)}var q=c.getState(),r=q.url,s=r.replace(x,""),t=s.replace(/\//g,"");switch(t){case"":j="home",g="home";break;case"home":j="home",g="home";break;case"switch":j=t,g="switch";break;case"about":j="about",g="about";break;case"contact":j="contact",g="contact";break;default:j=t,g="switch"===g?"switch":"works"}Core.scripts(j),Switchproject.img(top.imagesArray),d("#loading #diamond").removeAttr("class").attr("class",j),m||Core.mouseAnimation(0,0),Core.$_wrapper.off("click"),d(a).off("mousewheel DOMMouseScroll scroll"),d("body").off("mouseup mousemove"),d.ajax({xhr:function(){if(a.XMLHttpRequest){var c=new XMLHttpRequest;return c.addEventListener("progress",function(a){if(a.lengthComputable){var c=100*(a.loaded/a.total);f!==b?"works"==q.data.id&&Switchproject.init(f,h,c):d("#app").trigger("launchView",["true"])}},!1),c}},data:{work:j,color:h},url:r,success:function(a,c,e){switch(m&&(f!==b?"works"==q.data.id&&Switchproject.init(f,h,100):d("#app").trigger("launchView",["true"])),i=a,k=c,l=e,q.data.id){case"works":d("#app").on("launchView",function(){w(i,k,l),d("#app").off("launchView")});break;default:w(i,k,l)}},error:function(){return e.location.href=r,!1}})})}),b):!1})(window);