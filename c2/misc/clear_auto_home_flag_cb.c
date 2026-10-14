void __fastcall clear_auto_home_flag_cb(c2_fe_symbol *s)

{
  if ((s->cls == '\x01') && (((byte)s->storage & 0x70) == 0x10)) {
    s->attrs = s->attrs & 0xfffff7ff;
  }
  return;
}

