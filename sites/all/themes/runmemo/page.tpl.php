<div id="wrapper">
	<div id="inner-wrapper">

		<div class="header">

			<div id="logo-floater">
			<?php if ($logo || $site_title): ?>
			<?php if ($title): ?>
				<div id="branding">
					<strong><a href="<?php print $front_page ?>"> <?php if ($logo): ?>
							<img src="<?php print $logo ?>" id="logo" alt="runmemo_logo" /> <?php endif; ?>
					</a>
					</strong>
				</div>
				<?php else: /* Use h1 when the content title is empty */ ?>
				<h1 id="branding">
					<a href="<?php print $front_page ?>"> <?php if ($logo): ?> <img
						src="<?php print $logo ?>" id="logo" /> <?php endif; ?> </a>
				</h1>
				<?php endif; ?>
				<?php endif; ?>
			</div>

			<?php if ($primary_nav): print $primary_nav; endif; ?>
			<?php if ($secondary_nav): print $secondary_nav; endif; ?>

			<?php print render($page['menu']); ?>
			
			<?php
			if(!in_array('Photographer',$user->roles) && (arg(0)!='user') && (arg(0)!='login') && (!drupal_is_front_page()))
			{
			  ?>
			<div class="cart float-R">
			<?php print render($page['shopping_cart']); ?>
			</div>

			<?php }?>

		</div>
		<!-- header close -->

		<!-- <div id="container" class="clearfix">-->

		<div id="center">
			<div id="squeeze">
				<div class="right-corner">
					<div class="left-corner">
					<?php if($is_front):?>
					<?php //print $breadcrumb; ?>
					<?php if ($page['highlighted']): ?>
						<div id="highlighted">
						<?php print render($page['highlighted']); ?>
						</div>
						<?php endif; ?>
						<a id="main-content"></a>
						<?php


						if(!in_array('anonymous user',$user->roles))
						{
						  ?>
						  <?php if ($tabs): ?>
						<div id="tabs-wrapper" class="clearfix">
						<?php endif; ?>
						<?php print render($title_prefix); ?>
						<?php if ($title): ?>
							<h1 <?php print $tabs ? ' class="with-tabs"' : '' ?>>
							<?php print $title ?>
							</h1>
							<?php endif; ?>
							<?php print render($title_suffix); ?>
							<?php if ($tabs): ?>
							<?php print render($tabs); ?>
						</div>
						<?php endif; ?>
						<?php print render($tabs2); ?>
						<?php
						}
						else
						{
						  if((arg(0)!= 'login') && (arg(0) != 'user'))
						  {?>

						  <?php if ($tabs): ?>
						<div id="tabs-wrapper" class="clearfix">
						<?php endif; ?>
						<?php print render($title_prefix); ?>
						<?php if ($title): ?>
							<h1 <?php print $tabs ? ' class="with-tabs"' : '' ?>>
							<?php print $title ?>
							</h1>
							<?php endif; ?>
							<?php print render($title_suffix); ?>
							<?php if ($tabs): ?>
							<?php print render($tabs); ?>
						</div>
						<?php endif; ?>
						<?php print render($tabs2); ?>

						<?php }

						}
						?>
						<?php endif; ?>
						<?php print $messages; ?>
						<?php print render($page['help']); ?>
						<?php if ($action_links): ?>
    						<ul class="action-links">
    						<?php print render($action_links); ?>
    						</ul>
						<?php endif; ?>
                                                
                       <?php print render($page['header']); ?>
                       <?php print render($page['sidebar_first']); ?>
                            <?php if ($title): ?>
                                <h1 class ="page-title"><?php print $title ?></h1>
                            <?php endif; ?>
                              
                            <?php print render($page['content']); ?>
                          
                            <?php print render($page['sidebar_second']); ?>
    					

						<?php print render($page['footer']); ?>
					</div>



				</div>
			</div>
		</div>
	</div>


	<!--Page Footer-->
	<div class="footer">
		<div class="footer-inner">
			<div class="social-icon float-L">
				<a href="mailto:info@runmemo.com" target="_blank"><img
					src="<?php echo base_path().path_to_theme(); ?>/images/iconnect.png"
					width="167" height="27" alt="iconnect" />
				</a> <a href="http://www.facebook.com/pages/Runmemo/228101553914296"
					target="_blank"> <img
					src="<?php echo base_path().path_to_theme(); ?>/images/facebook-icon.png"
					width="32" height="32" alt="facebook" />
				</a> <a href="http://twitter.com/#!/runmemos" target="_blank"><img
					src="<?php echo base_path().path_to_theme(); ?>/images/twitter-icon.png"
					width="32" height="32" alt="twitter" />
				</a>
			</div>
			<p class="float-R">
				<small>© 2012</small> Runmemo
			</p>
		</div>
	</div>
	<!--footer ends-->

</div>
