char ** __cdecl cmdline_split(char *s,int unquote)

{
  byte *in;
  size_t sVar1;
  uchar *words;
  int rc;
  int rc_2;
  uchar *next;
  int rc_3;
  uchar *out;
  int rc_4;
  char **argv;
  char *text;
  int iVar2;
  int count;
  bool copy;
  int quote_out;
  bool in_quotes;
  char **word;
  byte c;
  
  count = 0;
  in_quotes = false;
  if ((s == (char *)0x0) || (in = (byte *)str_skip_spaces(s), *in == 0)) {
    return (char **)0x0;
  }
  sVar1 = strlen((char *)in);
  words = xmalloc(sVar1 + 1);
  c = *in;
  out = words;
joined_r0x00405802:
  if (c == 0) {
    argv = xmalloc(count * 4 + 4);
    iVar2 = 0;
    word = argv;
    for (; count != 0; count = count + -1) {
      text = str_skip_spaces((char *)words);
      unquote = (int)word;
      if (*text != '\0') {
        iVar2 = iVar2 + 1;
        unquote = (int)(word + 1);
        *word = text;
      }
      sVar1 = strlen(text);
      words = (uchar *)(text + sVar1 + 1);
      word = (char **)unquote;
    }
    argv[iVar2] = (char *)0x0;
    return argv;
  }
  do {
    quote_out = 0;
    s = (char *)0x0;
    copy = true;
    rc = _mbsncmp(in,(uchar *)"\\",1);
    while (rc == 0) {
      in = _mbsinc(in);
      s = s + 1;
      rc = _mbsncmp(in,(uchar *)"\\",1);
    }
    rc_2 = _mbsncmp(in,(uchar *)"\"",1);
    if (rc_2 == 0) {
      if (((uint)s & 1) == 0) {
        if (in_quotes) {
          next = _mbsinc(in);
          rc_3 = _mbsncmp(next,(uchar *)"\"",1);
          if (rc_3 != 0) goto LAB_00405896;
          in = _mbsinc(in);
          if (unquote == 0) {
            quote_out = 1;
          }
        }
        else {
LAB_00405896:
          copy = unquote == 0;
        }
        in_quotes = !in_quotes;
      }
      if (unquote != 0) {
        s = (char *)((uint)s >> 1);
      }
    }
    for (; s != (char *)0x0; s = s + -1) {
      _mbccpy(out,(uchar *)"\\");
      out = _mbsinc(out);
    }
    if (quote_out != 0) {
      s = (char *)quote_out;
      do {
        _mbccpy(out,(uchar *)"\"");
        out = _mbsinc(out);
        s = s + -1;
      } while (s != (char *)0x0);
    }
    if ((*in == 0) || ((!in_quotes && (rc_4 = _ismbcspace((uint)*in), rc_4 != 0)))) break;
    if (copy) {
      _mbccpy(out,in);
      out = _mbsinc(out);
    }
    in = _mbsinc(in);
  } while( true );
  *out = '\0';
  out = out + 1;
  count = count + 1;
  in = (byte *)str_skip_spaces((char *)in);
  c = *in;
  goto joined_r0x00405802;
}

