Make sure you have selected:

Who can register accounts?
0 Administrators only
X Visitors
0 Visitors, but administrator approval is required

At admin/config/people/accounts.

Then select 'Require a verification e-mail, but let users set their password directly on the registration form.' at:

Require e-mail verification when a visitor creates an account
0 Do not require a verification e-mail, and let users set their password on the registration form.
0 Require a verification e-mail, but wait for the approval e-mail to let users set their password.
X Require a verification e-mail, but let users set their password directly on the registration form.

You also have to change the 'Account Activation' welcome email template on the bottom of the same page.

By default, Drupal will send the following Email:

-----------------------------------------------------------------------------------------------------------------------

[user:name],

Your account at [site:name] has been activated.

You may now log in by clicking this link or copying and pasting it into your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

After setting your password, you will be able to log in at [site:login-url] in the future using:

username: [user:name]
password: Your password

--  [site:name] team

-----------------------------------------------------------------------------------------------------------------------

This will be confusing, because it also contains a login link, a link we do need anymore, because we already verified
the account, and the link will not work anyway. ( possible TODO ? )

The most simple way to fix this situation is to rewrite the template to look something like this:

-----------------------------------------------------------------------------------------------------------------------

[user:name],

Your account at [site:name] has been activated.

You may now log in by surfing to [site:login-url] with the username and password you used to register.

--  [site:name] team

-----------------------------------------------------------------------------------------------------------------------

That's all! The module is now configured correctly.

