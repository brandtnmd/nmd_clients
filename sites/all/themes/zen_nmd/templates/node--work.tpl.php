
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php if (isset($node->field_work_h1_keywords[$node->language][0]['value'])): ?>
<h1 class="nmdkeywords"><?php print $node->field_work_h1_keywords[$node->language][0]['value']; ?></h1>
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
    ?>
    
    <?php if ($content['field_work_feat_screen']): ?>
			<?php print render ($content['field_work_feat_screen']);?>
    <?php endif ?>
    

    
    <?php if ($content['field_work_url']): ?>
		<ul class="work-bar">
			<li><a href="<?php print ($content['field_work_url']);?>" class="btn-light">Visit Website</a> </li>
		</ul>  
    <?php endif ?>
    
     <div class="work-col-left">
        <?php if ($content['body']): ?>
        <h2>Project Description</h2>
			<?php print render ($content['body']);?>
    <?php endif ?>
    
    
    <?php if ($content['field_proj_comp']): ?>
    <h2>Project Completed</h2>
			<?php print render ($content['field_proj_comp']);?>
    <?php endif ?>
    

    
    <?php if (isset($node->field_work_test_ref[$node->language][0]['value'])): ?>
    	<h2>Testimonials</h2>
		<span class="testimonial-body"><?php print $node->field_work_test_ref[$node->language][0]['value']; ?></span>
	<?php endif; ?>
    
    
    
    
    
     </div><!-- /.work-col-left -->
     
      <div class="work-col-right">
     <?php if ($content['field_work_gallery']): ?>
     <h2>Screenshot Gallery</h2>
     <em>Click a thumbnail to see a larger version.</em>
			<?php print render ($content['field_work_gallery']);?>
    <?php endif ?>
     </div><!-- /.work-col-right -->

   
  </div><!-- /.content -->


    


  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div><!-- /.node -->




   