<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php if (isset($node->field_page_h1_keywords[$node->language][0]['value'])): ?>
<h1 class="nmdkeywords"><?php print $node->field_page_h1_keywords[$node->language][0]['value']; ?></h1>
<?php endif; ?>
  

  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

 

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_page_h1_keywords']);
      print render($content);
    ?>


    
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div><!-- /.node -->
