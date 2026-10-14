char * __cdecl action_expand_percent(char *out,char *tmpl,driver_ctx *ctx)

{
  uchar *upper;
  char *text;
  byte *dst;
  char *text_2;
  size_t len;
  uchar buf [256];
  cl_pass *pass;
  int batch_index;
  char *fullname;
  cl_srcfile *file;
  byte c;
  
  file = ctx->file;
  dst = (byte *)out;
  if (file == (cl_srcfile *)0x0) {
    pass = (cl_pass *)0x0;
    batch_index = -1;
    fullname = "";
  }
  else {
    fullname = file->fullname;
    batch_index = (int)file->batch_index;
    pass = ctx->pass;
  }
LAB_00405039:
  do {
    while( true ) {
      if (*tmpl == 0) {
        *dst = 0;
        return out;
      }
      if (*tmpl == 0x25) break;
      *dst = *tmpl;
      tmpl = tmpl + 1;
LAB_004050d0:
      dst = dst + 1;
    }
    *dst = 0;
    c = tmpl[1];
    tmpl = tmpl + 2;
    if (0x65 < c) {
      text = fullname;
      if (c == 0x66) {
LAB_004051b4:
        dst = (byte *)strcat_end((char *)dst,text);
      }
      else if (c == 0x6d) {
        text_2 = xmalloc(0x400);
        action_expand_percent(text_2,g_Fe_name,ctx);
        map_file_name((char *)dst,text_2);
        len = strlen((char *)dst);
        xfree(text_2);
        dst = dst + len;
      }
      else if (c == 0x74) {
        dst = (byte *)strcat_end((char *)dst,ctx->temp_prefix);
        if ((ctx->batch != (cl_compile_node *)0x0) && (batch_index != -1)) {
          dst[-6] = (char)(batch_index / 10) + 0x61;
          dst[-5] = (char)(batch_index % 10) + 0x30;
        }
      }
      else if (c == 0x78) {
        path_strip_extension((char *)buf,g_Fe_name);
LAB_00405121:
        dst = (byte *)strcat_end((char *)dst,(char *)buf);
      }
      goto LAB_00405039;
    }
    if (c == 0x65) {
      if (pass == (cl_pass *)0x0) {
        text = (char *)0x0;
      }
      else {
        text = pass->extra;
      }
      if (text == (char *)0x0) {
        text = "";
      }
      goto LAB_004051b4;
    }
    if (c == 0x25) {
      *dst = 0x25;
      goto LAB_004050d0;
    }
    if (c == 0x42) {
      path_base_name((char *)buf,fullname);
      upper = _mbsupr(buf);
      dst = (byte *)strcat_end((char *)dst,(char *)upper);
    }
    else {
      if (c == 0x58) {
        text = "dll";
        if (g_dll == 0) {
          text = "exe";
        }
        goto LAB_004051b4;
      }
      if (c == 0x62) {
        path_base_name((char *)buf,fullname);
        goto LAB_00405121;
      }
    }
  } while( true );
}

