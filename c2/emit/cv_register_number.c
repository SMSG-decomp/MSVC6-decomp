uint16_t __fastcall cv_register_number(c2_fe_symbol *s)

{
  if ((int)s->size < 5) {
    return (short)s->refcount + 1 + (short)((int)s->size >> 1) * 8;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x484);
}

