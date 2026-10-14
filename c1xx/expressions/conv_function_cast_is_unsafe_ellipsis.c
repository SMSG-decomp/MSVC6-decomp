char conv_function_cast_is_unsafe_ellipsis(c1_type *from,c1_type *to)

{
  if ((from->code == 0x80d) && (to->code == 0x80d)) {
    return '\0';
  }
  diag_fatal(1,".\\convert.cpp",0xc23);
}

