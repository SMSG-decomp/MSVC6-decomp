char * __cdecl path_set_default_extension(char *ext,char *path,char *base)

{
  uchar *sep;
  uchar *dot;
  uchar *dot_2;
  size_t len;
  uchar discard [256];
  uchar c;
  char first;
  
  first = *ext;
  if (first == '<') {
    ext = ext + 1;
  }
  sep = (uchar *)str_last_of(path,"\\/");
  dot_2 = (uchar *)path;
  if ((sep == (uchar *)0x0) || (dot_2 = sep, sep[1] != '\0')) {
    dot = _mbsrchr(dot_2,0x2e);
    if (dot == (uchar *)0x0) {
      len = strlen(path);
      dot = (uchar *)(path + len);
    }
    else if (first != '<') {
      dot = discard;
    }
  }
  else {
    if (base == (char *)0x0) {
      base = "%b";
    }
    dot = (uchar *)strcat_end(path,base);
  }
  *dot = '.';
  while( true ) {
    dot = dot + 1;
    c = *ext;
    if ((c == '\0') || (c == ',')) break;
    *dot = c;
    ext = ext + 1;
  }
  *dot = '\0';
  return (char *)(uchar *)ext;
}

