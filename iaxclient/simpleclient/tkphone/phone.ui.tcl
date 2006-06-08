#! /bin/sh
# the next line restarts using wish \
exec wish "$0" "$@"

# interface generated by SpecTcl version 1.2 from /export/home/suhler/new/phone.ui
#   root     is the parent window for this user interface

proc phone_ui {root args} {

	# this treats "." as a special case

	if {$root == "."} {
	    set base ""
	} else {
	    set base $root
	}
    
	frame $base.frame#1

	frame $base.extra

	entry $base.entry \
		-textvariable number

	button $base.hangup \
		-text hangup

	button $base.send \
		-text send

	button $base.b1 \
		-text 1

	button $base.b2 \
		-text 2

	button $base.b3 \
		-text 3

	button $base.b4 \
		-text 4

	button $base.b5 \
		-text 5

	button $base.b6 \
		-text 6

	button $base.b7 \
		-text 7

	button $base.b8 \
		-text 8

	button $base.b9 \
		-text 9

	button $base.bstar \
		-text *

	button $base.b0 \
		-text 0

	button $base.bsharp \
		-text #

	label $base.status \
		-text status \
		-textvariable status \
		-width 20

	label $base.message \
		-anchor nw \
		-cursor hand1 \
		-justify left \
		-relief ridge \
		-text {- messages -} \
		-textvariable Messages


	# Add contents to menus

	# Geometry management

	grid $base.frame#1 -in $root	-row 2 -column 1  \
		-columnspan 3
	grid $base.extra -in $root	-row 3 -column 4  \
		-rowspan 4 \
		-sticky new
	grid $base.entry -in $root	-row 1 -column 1  \
		-columnspan 3
	grid $base.hangup -in $base.frame#1	-row 1 -column 1 
	grid $base.send -in $base.frame#1	-row 1 -column 2 
	grid $base.b1 -in $root	-row 3 -column 1  \
		-sticky nesw
	grid $base.b2 -in $root	-row 3 -column 2  \
		-sticky nesw
	grid $base.b3 -in $root	-row 3 -column 3  \
		-sticky nesw
	grid $base.b4 -in $root	-row 4 -column 1  \
		-sticky nesw
	grid $base.b5 -in $root	-row 4 -column 2  \
		-sticky nesw
	grid $base.b6 -in $root	-row 4 -column 3  \
		-sticky nesw
	grid $base.b7 -in $root	-row 5 -column 1  \
		-sticky nesw
	grid $base.b8 -in $root	-row 5 -column 2  \
		-sticky nesw
	grid $base.b9 -in $root	-row 5 -column 3  \
		-sticky nesw
	grid $base.bstar -in $root	-row 6 -column 1  \
		-sticky nesw
	grid $base.b0 -in $root	-row 6 -column 2  \
		-sticky nesw
	grid $base.bsharp -in $root	-row 6 -column 3  \
		-sticky nesw
	grid $base.status -in $root	-row 7 -column 1  \
		-columnspan 4 \
		-sticky ew
	grid $base.message -in $root	-row 8 -column 1  \
		-columnspan 4 \
		-sticky new

	# Resize behavior management

	grid rowconfigure $root 1 -weight 0 -minsize 30 -pad 0
	grid rowconfigure $root 2 -weight 0 -minsize 30 -pad 0
	grid rowconfigure $root 3 -weight 0 -minsize 30 -pad 0
	grid rowconfigure $root 4 -weight 0 -minsize 30 -pad 0
	grid rowconfigure $root 5 -weight 0 -minsize 30 -pad 0
	grid rowconfigure $root 6 -weight 0 -minsize 7 -pad 0
	grid rowconfigure $root 7 -weight 0 -minsize 5 -pad 0
	grid rowconfigure $root 8 -weight 1 -minsize 5 -pad 0
	grid columnconfigure $root 1 -weight 0 -minsize 30 -pad 0
	grid columnconfigure $root 2 -weight 0 -minsize 30 -pad 0
	grid columnconfigure $root 3 -weight 0 -minsize 30 -pad 0
	grid columnconfigure $root 4 -weight 0 -minsize 0 -pad 0

	grid rowconfigure $base.frame#1 1 -weight 0 -minsize 30 -pad 0
	grid columnconfigure $base.frame#1 1 -weight 0 -minsize 30 -pad 0
	grid columnconfigure $base.frame#1 2 -weight 0 -minsize 30 -pad 0
# additional interface code
# end additional interface code

}


# Allow interface to be run "stand-alone" for testing

catch {
    if [info exists embed_args] {
	# we are running in the plugin
	phone_ui .
    } else {
	# we are running in stand-alone mode
	if {$argv0 == [info script]} {
	    wm title . "Testing phone_ui"
	    phone_ui .
	}
    }
}
