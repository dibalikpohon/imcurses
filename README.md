# vimcurses
Instant messaging app with vim style using ncurses and ASIO

What it can do:
1. 1v1 chat
2. Send attachments
3. Allow replying (future release)
4. Join a group chat

## Commands:
### First thing to do:
`:h` -- host a chat  
`:c <ip>` -- (join a chat) connect to a user  
`:e` -- end chat  

### In a chat:
`[ESC]` -- exit chat mode (to normal mode)  
`t` -- to type (chat mode)  
  
`k` -- hightlight chat above  
`j` -- hightlight chat below  
  
`:aa {path}` -- send an attachment from a file (should go to normal mode and hightlight a chat)  
`:ac {path} {caption}` -- send an attachment from a file (with caption)  
  
### on hightligting
`r` -- reply to a chat (future release)  
`d {path}` -- download attachment to disk
