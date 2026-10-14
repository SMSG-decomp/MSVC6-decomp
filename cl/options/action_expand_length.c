int __cdecl action_expand_length(char *tmpl,driver_ctx *ctx)

{
  int len;
  char *text;
  cl_pass *pass;
  byte *next;
  char buf [256];
  int total;
  byte c;
  driver_ctx *drv;
  byte c_2;
  
  drv = ctx;
  pass = (cl_pass *)0x0;
  total = 0;
  if (ctx->file == (cl_srcfile *)0x0) {
    ctx = (driver_ctx *)s_empty;
  }
  else {
    pass = ctx->pass;
    ctx = (driver_ctx *)ctx->file->fullname;
  }
LAB_004052b7:
  do {
    while( true ) {
      c = *tmpl;
      if (c == 0) {
        return total;
      }
      next = (byte *)(tmpl + 1);
      if (c != 0x22) break;
LAB_00405388:
      total = total + 2;
      tmpl = (char *)next;
    }
    if (c == 0x25) {
      c_2 = *next;
      tmpl = tmpl + 2;
      if (c_2 < 0x66) {
        if (c_2 == 0x65) {
          if (pass == (cl_pass *)0x0) {
            text = (char *)0x0;
          }
          else {
            text = pass->extra;
          }
          if ((driver_ctx *)text != (driver_ctx *)0x0) goto LAB_0040537a;
          goto LAB_004052b7;
        }
        if (c_2 == 0x25) goto LAB_004052dc;
        if (c_2 != 0x42) {
          if (c_2 == 0x58) {
            total = total + 3;
            goto LAB_004052b7;
          }
          if (c_2 != 0x62) goto LAB_004052b7;
        }
        path_base_name(buf,(char *)ctx);
LAB_00405317:
        len = quoted_length(buf);
      }
      else {
        text = (char *)ctx;
        if (c_2 != 0x66) {
          if (c_2 == 0x6d) {
            total = total + 0x400;
            goto LAB_004052b7;
          }
          if (c_2 != 0x74) {
            if (c_2 == 0x78) {
              path_strip_extension(buf,g_Fe_name);
              goto LAB_00405317;
            }
            goto LAB_004052b7;
          }
          text = drv->temp_prefix;
        }
LAB_0040537a:
        len = quoted_length(text);
      }
      total = total + len;
      goto LAB_004052b7;
    }
    tmpl = (char *)next;
    if (c == 0x5c) goto LAB_00405388;
LAB_004052dc:
    total = total + 1;
  } while( true );
}

