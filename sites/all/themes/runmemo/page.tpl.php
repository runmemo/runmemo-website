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
			
			<div class="float-R">
				<div class="login-btn-lft float-L"></div>
				<div class="login-btn float-L">
				<?php
				global $user;
				if (empty($user->name)) {?>
					<div class="login-btn-mid float-L">
						<a href="<?php echo base_path();?>user"><span class="float-L">Login</span>
						</a> <img
							src="<?php echo base_path().path_to_theme(); ?>/images/separator.png"
							width="1" height="23" alt="separator" /> <a
							href="<?php echo base_path();?>login"><span
							class="float-R underline">Register</span> </a>
					</div>
					<?php
				}
				else {?>
					<div class="login-btn-mid float-L">
						<a href="<?php echo base_path();?>user">
						<span class="float-L">My Account</span> </a> <img
							src="<?php echo base_path().path_to_theme(); ?>/images/separator.png"
							width="1" height="23" alt="separator" /> <a
							href="<?php echo base_path();?>user/logout"><span
							class="float-R underline">Logout</span> </a>
					</div>
					<?php }?>
				</div>
				<div class="login-btn-rig float-L"></div>
			</div>

			<?php
			if(!in_array('Photographer',$user->roles) && (arg(0)!='user') && (arg(0)!='login') && (!drupal_is_front_page()))
			{
			  ?>
			<div class="cart float-R">
			<?php print render($page['shopping_cart']); ?>
			</div>

			<?php }?>

		</div>
		<!--header close-->
		<div class="gray-bdr"></div>

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

						<div class="clearfix sidebars">
						
    						<?php if ($page['sidebar_first']): ?>
    							<div id="sidebar-first" class="sidebar">
    							  <?php print render($page['sidebar_first']); ?>
    							</div>
    						<?php endif; ?>

      						<?php $path=explode('/',request_uri()); //bprint_r($parts);print_r($_REQUEST);?>
      						<?php print render($page['header']); ?>
      						<?php print render($page['content']); ?>
      						<?php print render($page['sidebar_second']); ?>
    					
						</div>
						<?php print render($page['footer']); ?>
					</div>



				</div>
			</div>
		</div>

				
		<!-- Region Recent Events -->
		<?php if($is_front):?>
		<div class="region float-L region-recent-events">
			<div class="cont-header-bg float-L">
				<h1 class="float-L">Recent Events</h1>
			</div>
			<div class="cont-lft float-L recent-event recent-event-left">
			<?php print render($page['recent_event_left']); ?>
			</div>
			<div class="cont-rig float-R recent-event recent-event-right">
			<?php print render($page['recent_event_right']); ?>
			</div>
		</div>
		<div class="clr"></div>
		<?php endif; ?>
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
