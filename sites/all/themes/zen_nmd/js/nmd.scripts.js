$(document).ready(function(){
	$('#nmd-slider')
	.anythingSlider({
autoPlay            : true,
delay               : 6000,
pauseOnHover        : true,
		resizeContents      : false,
		 buildArrows   : false,

		theme: "metallic"
	})
	.anythingSliderFx({
		// base FX definitions
		// '.selector' : [ 'effect(s)', 'distance/size', 'time', 'easing' ] - 'time' and 'easing' are optional parameters
		'.textSlide span'       : [  'top', '500px', '600', 'easeOutElastic'  ],
		'.textSlide a.btn-red'       : [  'top', '500px', '600', 'easeOutElastic'  ],
		'.textSlide img'       : [  'top', '200px', '1200', 'easeOutElastic'  ]
/*,

		// for more precise control, use the "in" and "out" definitions
		// in = the animation that occurs when you slide "in" to a panel
		    inFx  : {
		     '.textSlide h3'  : { opacity: 1, top  : 0, duration: 400, easing : 'easeOutBounce' },
		     '.textSlide li'  : { opacity: 1, left : 0, duration: 400 },
		     '.textSlide img' : { opacity: 1, duration: 400 },
		     '.quoteSlide'    : { top : 0, duration: 400, easing : 'easeOutElastic' },
		     '.expand'        : { width: '100%', top: '0%', left: '0%', duration: 400, easing : 'easeOutBounce' }
		    },
		// out = the animation that occurs when you slide "out" of a panel
		// (it also occurs before the "in" animation)
		     outFx : {
		     '.textSlide h3'      : { opacity: 0, top  : '-100px', duration: 350 },
		     '.textSlide li:odd'  : { opacity: 0, left : '-200px', duration: 350 },
		     '.textSlide li:even' : { opacity: 0, left : '200px',  duration: 350 },
		     '.textSlide img'     : { opacity: 0, duration: 350 },
		     '.quoteSlide:first'  : { top : '-500px', duration: 350 },
		     '.quoteSlide:last'   : { top : '500px', duration: 350 },
		     '.expand'            : { width: '10%', top: '50%', left: '50%', duration: 350 },
		    } */
	});
		});







// jQuery Uniform for to style up forms
 $(function(){
        $("input, textarea, select, button").uniform();
      });
      

      
// jQuery FAQ accordion      
 $(function(){         
      $(document).ready(function($) {
       $('.view-faqs .views-field-body').hide();
       $('.view-faqs h2').click(function(){
               $('.view-faqs .views-field-body').slideUp();
               $(this).parent().next().slideDown();
               return false;
       });
});

 }); 
 
 
 
 
 
 
 // Rounded corners for our good ol' friend IE     
$(function(){
$('.anythingControls .thumbNav a').corner("10px");
//$('a.btn-light').corner("10px");
});
 
 
 
  
 // Twitter   
 $(document).ready(function(){
        $(".tweet").tweet({
            username: "newmediadenver",
            join_text: "auto",
            avatar_size: 32,
            count: 1,
            auto_join_text_default: "we said,", 
            auto_join_text_ed: "we",
            auto_join_text_ing: "we were",
            auto_join_text_reply: "we replied to",
            auto_join_text_url: "we were checking out",
            loading_text: "loading tweets..."
        });
    });
 
 
 
 
 
 
