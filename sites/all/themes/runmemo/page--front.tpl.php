<div id="wrapper">
  <div id="inner-wrapper">

    <div class="header">


<div id="logo-floater">
        <?php if ($logo || $site_title): ?>
          <?php if ($title): ?>
            <div id="branding"><strong><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>"  id="logo" />
            <?php endif; ?>
            </a></strong></div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="branding"><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>"  id="logo" alt="runmemo_logo"/>
            <?php endif; ?>
            </a></h1>
        <?php endif; ?>
        <?php endif; ?>
        </div>



   
 <?php if ($primary_nav): print $primary_nav; endif; ?>
        <?php if ($secondary_nav): print $secondary_nav; endif; ?>






<?php print render($page['header']); ?>
      



    </div>

    <div class="clr"></div>


   <!-- <div id="container" class="clearfix">-->

    <div id="center"><div id="squeeze"><div class="right-corner"><div class="left-corner">
         <!--  <?php //print $breadcrumb; ?>
          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php if ($tabs): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1<?php print $tabs ? ' class="with-tabs"' : '' ?>><?php print $title ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($tabs2); ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>-->
	<?php print $messages; ?>
          <div class="clearfix"> 
		<div class="gray-bdr" style="margin-top:30px;"></div>
		 <?php if ($page['sidebar_first']): ?>
        <div id="sidebar-first" class="sidebar">
          <?php print render($page['sidebar_first']); ?>
        </div>
	
      <?php endif; ?>

	
	<div class="title" style="width:100%;">
          <?php if (arg(0) == 'user' && arg(1) == 'register') : ?>
          <h1 class="new_account_heading">  New Photograper Registration </h1> <h1 class="login_heading">I already have a Photographer account </h1>
          <?php elseif (arg(0) == 'user' && empty($messages)&& arg(1) == null) : ?>
           <h1 class="log_in">  User Login</h1>
          <?php endif ; ?>
	</div>
		
            <?php print render($page['content']); ?>
          </div>
                    
      </div>
	<?php if ($page['sidebar_second']): ?>
        <div id="sidebar-second" class="sidebar" style="align:right;">
          <?php print render($page['sidebar_second']); ?>
        </div>
      <?php endif; ?>
</div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->

<!--</div>-->

	<div class="clr"></div>
    <div class="gray-bdr"></div>
	
    <div class="content float-L">
      <div class="cont-header-bg float-L">
        <h1 class="float-L">Recent Events</h1>
      </div>
      <div class="cont-lft float-L">
        <div class="cont-lft-header">Royal Parks Half Maraphone 2011</div>
        <div class="find-palyers float-L">
          <ul>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player.png" width="96" height="139" alt="runmemo_player"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player1.png" width="96" height="139" alt="runmemo_player1"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player2.png" width="96" height="139" alt="runmemo_player2"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player3.png" width="96" height="139" alt="runmemo_player3"/></li>
          </ul>
        </div>
	
        <div class="float-R w-275">
	<?php print render($page['recent_event1_submit']); ?>
	</div>
      </div>
      <div class="cont-rig float-L">
        <div class="cont-lft-header">Man Of Isles Half Marathon 2011</div>
         <div class="find-palyers float-L">
          <ul>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player.png" width="96" height="139" alt="runmemo_player"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player1.png" width="96" height="139" alt="runmemo_player"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player2.png" width="96" height="139" alt="runmemo_player"/></li>
            <li><img src="<?php echo base_path().path_to_theme(); ?>/images/find-player3.png" width="96" height="139" alt="runmemo_player"/></li>
          </ul>
        </div>
	<div class="float-R w-275">
	<?php print render($page['recent_event2_submit']); ?>
	</div>
      </div>
    </div>
    <div class="clr"></div>
	

      </div>



  <div class="footer"><!--footer-->
  <div class="footer-inner">
  <div class="social-icon float-L">
  <a href="mailto:info@runmemo.com"  target="_blank"><img src="<?php echo base_path().path_to_theme(); ?>/images/iconnect.png" width="167" height="27"  alt="iconnect"/></a>
 <a href="http://www.facebook.com/pages/Runmemo/228101553914296"  target="_blank"> <img src="<?php echo base_path().path_to_theme(); ?>/images/facebook-icon.png" width="32" height="32" alt="facebook"/></a>
  <a href="http://twitter.com/#!/runmemos"  target="_blank"><img src="<?php echo base_path().path_to_theme(); ?>/images/twitter-icon.png" width="32" height="32" alt="twitter"/></a>
  </div>
  <p class="float-R"><small>© 2012</small>  Runmemo</p>
  </div>
  </div><!--footer ends-->

</div>

