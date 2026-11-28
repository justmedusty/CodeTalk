# CodeTalk

This is a tool for encrypting plain language messages over FM, SSB, CW, or other forms or radio. The sender and receiver must have
the same keyfile and running this program from their transmit location or be able to get to it later and write down the encrypted message.

The level of security is dependent on the user, it can be very low or extremely high/unbreakable depending on the user choice of keyfile options.

This is a command line application meant to be run on a mobile device, laptop, or desktop computer.

Generally , you do not need to take the absolute max security option (OTP) unless you know you are being listened to and surveiled. As an example,
a substitution cipher with a transcolumnar transposition addition while good at obscuring a message, can be broken over time due to patterns that will
reveal themselves. 

I am assuming the user of this program understands opsec and understands how secure they need to be in their transmissions. If you are in the middle of nowhere using basic simplex
operation with few listeners, a simple sub cipher will be plenty. 

One time pad is the best.

Simple substitution especially when mixed with columnar transposition is strong enough for the vast majority of use cases, but it can be broken over time if someone
is recording all of the messages and cryptanalyzing them.

To be most brief and secure, messages should be as short as possible, and even should be misspelled intentionally to make it harder to cryptanalyze.

Examples of such:

"I got your message, I am coming to your location now" -> "gt y msg cmg nw"
"I am behind the third hill to the east, under the large spruce tree" -> "i bhnd 3d hll 2 est,udr lge sprce tr3e"

Doing such will make it much, much harder for anybody to analyze and crack your message, and will remove a lot of traditional patterns that will appear in messages
such as common vowels and whatnot. It will also make your transmissions much shorter which also adds its own security and ease of use. Avoiding repeating characters
will massively improve the security of your encrypted analog communication.