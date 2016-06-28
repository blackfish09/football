#!/usr/bin/perl

use strict;
use warnings;

# Argument count
my $ARGC = @ARGV;

# If no parameters -> show usage
if ($ARGC < 1) {
    print("Use this to generate class header and source files!\n");
    print("Usage:\n\t$0 [-s] -c <class-name>\n");
    print("Params:\n");
    print("\t-s\t- generate source file\n");
    print("\t-c <name>\t- class name\n");
    exit 1;
}

# Get All parameters
my $source = (grep(/-s/, @ARGV)) ? 1 : 0;
my $classname;

# Get names
for my $i (0..$#ARGV) {
    if ($ARGV[$i] eq "-c") {
	$classname = $ARGV[$i+1];
    }
}

# If class name not exists -> exit
if (!$classname) {
    print("[FAIL] Parameter: -c <classname> required!\n");
    exit 1;
}

# Generate filenames
my $header_file = "../include/";
$header_file .= $classname;
$header_file .= ".h";

my $source_file = "../src/";
$source_file .= $classname;
$source_file .= ".cpp";

# If file exists -> exit
if (-e $header_file) {
    print("[FAIL] $header_file exists!\n");
    exit 1;
}

if ($source && -e $source_file) {
    print("[FAIL] $source_file exists!\n");
    exit 1;
}

# Generate header string content
my $guard = uc $classname;
my $h_content = "".
"#ifndef INCLUDE__".$guard."_H\n".
"#define INCLUDE__".$guard."_H\n".
"\n".
"namespace bfish\n".
"{\n".
"  class $classname;\n".
"}\n".
"\n".
"class bfish::$classname {\n".
" public:\n".
"\n".
" private:\n".
"  ".$classname."(void);\n".
"  virtual ~".$classname."(void);\n".
"  ".$classname."(const ".$classname."& prev);\n".
"  ".$classname."& operator=(const ".$classname."& prev);\n".
"  ".$classname."(const ".$classname."&& prev);\n".
"  ".$classname."& operator=(const ".$classname."&& prev);\n".    
"};\n".
"\n".
"#endif\n";

my $HFH;
open($HFH, ">$header_file") or die "[FAIL] Something with IO header file\n";
print $HFH $h_content;
close($HFH);
print("[ Ok ] Header file writen successfuly\n");


my $s_content;
my $SFH;
if ($source) {
    $s_content = "".
	"#include \"../include/".$classname.".h\"\n".
	"/// PUBLIC ----------------------------------------------------------------------\n".
	"/// PROTECTED--------------------------------------------------------------------\n".
	"/// PRIVATE----------------------------------------------------------------------";
    open($SFH, ">$source_file") or die "[FAIL] Something with IO source file\n";
    print $SFH $s_content;
    close($SFH);
    print("[ Ok ] Source file writen successfuly\n");
}

print("Dont forget to change Makefile!\n");
