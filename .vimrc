" URL: http://vim.wikia.com/wiki/Example_vimrc
" " Authors: http://vim.wikia.com/wiki/Vim_on_Freenode
" " Description: A minimal, but feature rich, example .vimrc. If you are a
"      newbie, basing your first .vimrc on this file is a good
" choice.
"      If you're a more advanced user, building your own .vimrc
" based
"      on this file is still a good idea.
"  
"  "------------------------------------------------------------
"  " Features {{{1
"  "
"  " These options and commands enable some very useful features in Vim, that
"  " no user should have to live without.

" Set 'nocompatible' to ward off unexpected things that your distro might
" have made, as well as sanely reset options when re-sourcing .vimrc
set nocompatible

" Attempt to determine the type of a file based on its name and possibly
filetype indent plugin on

" Enable syntax highlighting
syntax on


"------------------------------------------------------------
" Must have options {{{1
"
" These are highly recommended options.

set hidden

" Note that not everyone likes working this way (with the hidden
" Alternatives include using tabs or split windows instead of
" window as mentioned above, and/or either of the following options:
" set confirm
" set autowriteall

" Better command-line completion
set wildmenu

" Show partial commands in the last line of the screen
set showcmd

" Highlight searches (use <C-L> to temporarily turn off
" mapping of <C-L> below)
set hlsearch

" Modelines have historically been a source of security
" such, it may be a good idea to disable them and use the
" script,
" set nomodeline


"------------------------------------------------------------
" Usability options {{{1
"
" These are options that users frequently set in their .vimrc.
" change Vim's behaviour in ways which deviate from the true
" which are considered to add usability. Which, if any, of
" use is very much a personal preference, but they are

" Use case insensitive search, except when using capital
set ignorecase
set smartcase

" Allow backspacing over autoindent, line breaks and start
set backspace=indent,eol,start

" When opening a new line and no filetype-specific
" the same indent as the line you're currently on. Useful
set autoindent

" Stop certain movements from always going to the first
" While this behaviour deviates from that of Vi, it does
" coming from other editors would expect.
set nostartofline

" Display the cursor position on the last line of the
" line of a window
set ruler

" Always display the status line, even if only one
set laststatus=2

" Instead of failing a command because of unsaved
" dialogue asking if you wish to save changed files.
set confirm

" Use visual bell instead of beeping when doing
set visualbell

" And reset the terminal code for the visual bell. If
" this line is also included, vim will neither flash
" is unset, this does nothing.
set t_vb=

" Enable use of the mouse for all modes
set mouse=a

" Set the command window height to 2 lines, to
set cmdheight=2

" Display line numbers on the left
set number

" Quickly time out on keycodes, but never time
set notimeout ttimeout ttimeoutlen=200

" Use <F11> to toggle between 'paste' and
set pastetoggle=<F11>


"------------------------------------------------------------
" Indentation options {{{1
"
" Indentation settings according to personal

" Indentation settings for using 4 spaces
" Do not change 'tabstop' from its default
set shiftwidth=4
set softtabstop=4
set expandtab

" Indentation settings for using hard tabs
" four characters wide.
"set shiftwidth=4
"set tabstop=4


"------------------------------------------------------------
" Mappings {{{1
"
" Useful mappings

" Map Y to act like D and C, i.e. to yank
" which is the default
map Y y$

" Map <C-L> (redraw screen) to also turn
" next search
nnoremap <C-L> :nohl<CR><C-L>
