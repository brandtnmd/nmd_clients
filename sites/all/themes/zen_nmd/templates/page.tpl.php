



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
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if ($tabs = render($tabs)): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <!-- AddThis Button BEGIN -->
<div class="addthis_toolbox addthis_default_style">
<a class="addthis_button_facebook_like" fb:like:layout="button_count"></a>
<a class="addthis_button_tweet"></a>
<a class="addthis_button_google_plusone" g:plusone:size="medium"></a>
<a class="addthis_counter addthis_pill_style"></a>
</div>
<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=xa-4e80f06e22f47999"></script>
<!-- AddThis Button END -->
      <?php print $feed_icons; ?>
    </div></div><!-- /.section, /#content -->

    

        <?php print render($page['navigation']); ?>

  

    <?php print render($page['sidebar_first']); ?>

    <?php print render($page['sidebar_second']); ?>

  </div></div><!-- /#main, /#main-wrapper -->
  <?php print render($page['footer']); ?>

</div></div><!-- /#page, /#page-wrapper -->

<?php print render($page['bottom']); ?>
