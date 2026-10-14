char * __cdecl msg_format(int *len,char *fmt,va_list args)

{
  int n;
  uchar *out;
  uchar *out_2;
  size_t slen;
  char *grown;
  int n_3;
  int n_4;
  int n_2;
  va_list ap;
  uchar conv;
  uchar *arg_c;
  uint *arg_u;
  char *s;
  
  if (g_format_buffer == (char *)0x0) {
    g_format_buffer = xmalloc(g_format_buffer_size + 0x80);
  }
  out_2 = (uchar *)g_format_buffer;
  if (*fmt != '\0') {
    ap = args + -4;
    do {
      n = _mbsncmp((uchar *)fmt,(uchar *)"%",1);
      if (n == 0) {
        fmt = (char *)_mbsinc((uchar *)fmt);
        conv = *fmt;
        if (conv == 'c') {
          arg_c = (uchar *)(ap + 4);
          ap = ap + 4;
          *out_2 = *arg_c;
          out_2 = _mbsinc(out_2);
        }
        else if (conv == 'd') {
LAB_00405ca7:
          n_3 = _mbsncmp((uchar *)fmt,(uchar *)"d",1);
          arg_u = (uint *)(ap + 4);
          ap = ap + 4;
          n_4 = uint_to_string(*arg_u,(char *)out_2,(-(uint)(n_3 != 0) & 6) + 10);
          out_2 = out_2 + n_4;
        }
        else if (conv == 's') {
          s = *(char **)(ap + 4);
          ap = ap + 4;
          slen = strlen(s);
          if ((uint)g_format_buffer_size <= out_2 + (slen - (int)g_format_buffer)) {
            do {
              g_format_buffer_size = g_format_buffer_size * 2;
            } while ((uint)g_format_buffer_size <= out_2 + (slen - (int)g_format_buffer));
            grown = xmalloc((size_t)(g_format_buffer_size + 0x80));
            memcpy(grown,g_format_buffer,(int)out_2 - (int)g_format_buffer);
            out_2 = out_2 + ((int)grown - (int)g_format_buffer);
            xfree(g_format_buffer);
            g_format_buffer = grown;
          }
          strcpy((char *)out_2,s);
          out_2 = out_2 + slen;
        }
        else {
          if (conv == 'x') goto LAB_00405ca7;
          _mbccpy(out_2,(uchar *)"%");
          out = _mbsinc(out_2);
          _mbccpy(out,(uchar *)fmt);
          out_2 = _mbsinc(out);
        }
      }
      else {
        _mbccpy(out_2,(uchar *)fmt);
        out_2 = _mbsinc(out_2);
      }
      fmt = (char *)_mbsinc((uchar *)fmt);
    } while (*fmt != '\0');
  }
  *out_2 = '\0';
  n_2 = (int)out_2 - (int)g_format_buffer;
  *len = n_2;
  if (n_2 < g_format_buffer_size + 0x80) {
    return g_format_buffer;
  }
  cl_error(0);
}

