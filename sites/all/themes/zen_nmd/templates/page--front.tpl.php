<div id="navigation"><div class="section clearfix">
<a href="/" class="logo"></a>
         <?php print render($page['primary-navigation']); ?>
</div></div><!-- /.section, /#navigation -->         
         
	
       

<!-- AnythingSlider #2 -->
   <ul id="nmd-slider">
    <li id="change" class="panel" style="background: url(/sites/all/themes/zen_nmd/images/panel-change.jpg) center center no-repeat;">

     <div class="textSlide">
		<?php print render($page['slideshow-change']); ?>
</div>
    </li>
    <li id="design" class="panel" style="background: url(/sites/all/themes/zen_nmd/images/panel-design.jpg) center center no-repeat;">

     <div class="textSlide">
     <?php print render($page['slideshow-design']); ?>
</div>
    </li>
    <li id="web-dev" class="panel" style="background: url(/sites/all/themes/zen_nmd/images/panel-drupal.jpg) center center no-repeat;">
     <div class="textSlide">
   <?php print render($page['slideshow-web-dev']); ?>
      
      
      
     </div>
    </li>
     <li id="seo" class="panel" style="background: url(/sites/all/themes/zen_nmd/images/panel-seo.jpg) center center no-repeat;">
     <div class="textSlide">
      <?php print render($page['slideshow-seo']); ?>
     </div>
    </li>
       </ul>
   <!--END AnythingSlider #2 -->









		
		
		
		
		
		

	
	
<div id="page-wrapper" ><div id="page">
  <div id="main-wrapper"><div id="main" class="clearfix">
		<div id="featured-blocks"><?php print render($page['content-top']); ?></div>
		<img src="/sites/all/themes/zen_nmd/images/ruler.png" alt="NewMedia" width="940" height="47" />
    <div id="content" class="column"><div class="section">
            <?php print render($page['content-frontpage']); ?>
    </div></div><!-- /.section, /#content -->
	

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
	
  </div></div><!-- /#main, /#main-wrapper -->
  <?php print render($page['footer']); ?>

</div></div><!-- /#page, /#page-wrapper -->



<div id="content-bottom">
<div class="tweet"></div>
	<div class="section clearfix">

	<?php print render($page['content-bottom']); ?>
</div></div>



<?php print render($page['bottom']); ?>

