



<?php print render($page['seo']); ?>


<div id="navigation"><div class="section clearfix">
<a href="/" class="logo"></a>
         <?php print render($page['primary-navigation']); ?>
</div></div><!-- /.section, /#navigation -->         
         
	<div id="header"><div class="section clearfix">
		<?php print render($page['header']); ?>
	</div></div><!-- /.section, /#header -->







<div id="page-wrapper" ><div id="page">
	


  <div id="main-wrapper"><div id="main" class="clearfix">

    <div id="content" class="column"><div class="section">
      <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
            <?php print $messages; ?>
      <?php if ($tabs = render($tabs)): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print render($page['help']); ?>
           <?php print render($page['content-top']); ?>
      
      <?php print $feed_icons; ?>
    </div></div><!-- /.section, /#content -->

    

        <?php print render($page['navigation']); ?>

  

    <?php print render($page['sidebar_first']); ?>

    <?php print render($page['sidebar_second']); ?>

  </div></div><!-- /#main, /#main-wrapper -->
  <?php print render($page['footer']); ?>

</div></div><!-- /#page, /#page-wrapper -->

<?php print render($page['bottom']); ?>
