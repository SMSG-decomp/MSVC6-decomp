int __cdecl format_storage_class(int buf,uint spec0,uint spec1,uint spec2)

{
  int iVar1;
  char *s;
  
  if (buf == 0) {
    buf = format_buffer_alloc();
  }
  switch(spec0 & 7) {
  case 0:
    s = "";
    break;
  case 1:
    s = "extern";
    break;
  case 2:
    s = "/*global*/";
    break;
  case 3:
    s = "static";
    break;
  case 4:
    s = "auto";
    break;
  case 5:
    s = "register";
    break;
  case 6:
    s = "/* really */ register";
    break;
  case 7:
    s = "typedef";
    break;
  default:
    s = "/*CLASS?*/";
  }
  format_buffer_append_string(buf,s);
  format_buffer_append_char(buf,' ');
  iVar1 = format_declspec_attributes(buf,spec0,(void *)spec1,spec2);
  return iVar1;
}

