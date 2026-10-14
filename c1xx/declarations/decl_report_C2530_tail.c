c1_symbol * __cdecl decl_report_C2530_tail(c1_symbol *p3,c1_symbol *stand_in,void *name)

{
  byte bVar1;
  c1_symbol *cls;
  c1_type *pcVar2;
  
  diag_error(0x212,name);
  if ((stand_in->flags22 & 2) != 0) {
    decl_define_variable(stand_in);
  }
  pcVar2 = p3->type;
  while ((bVar1 = (byte)pcVar2->code, (bVar1 & 0x8f) == 0x83 || ((bVar1 & 0x83) == 0x81))) {
    pcVar2 = pcVar2->base;
  }
  if (((byte)pcVar2->flags >> 5 & 1) != 0) {
    stand_in->flags21 = stand_in->flags21 | 0x10;
  }
  stand_in->flags2 = stand_in->flags2 | 4;
  if ((((byte)g_compile_flags_cc & 1) == 0) &&
     (cls = sym_class_needing_init(stand_in), cls != (c1_symbol *)0x0)) {
    if ((cls->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(cls);
    }
    bVar1 = ((cls->detail).cls)->implicit_state41 & 0x10;
    if (((bVar1 != 0) || ((((cls->detail).cls)->implicit_state43 & 0x10) != 0)) && (bVar1 == 0)) {
      sym_queue_destructible_object(stand_in);
    }
  }
  g_file_scope_decl_since_body = 1;
  return stand_in;
}

