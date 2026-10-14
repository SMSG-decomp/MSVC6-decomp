void __cdecl init_begin_dynamic_initializer(c1_symbol *sym)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  c1_symbol *pcVar4;
  
  if (((g_compile_flags_c4 & 0x20) == 0) && ((g_compile_flags_c4 & 0x20000) == 0)) {
    func_body_begin_generated((c1_symbol *)0x0);
  }
  else {
    init_warn_local_static_thread_safety(sym);
  }
  uVar3 = g_compile_flags_c4 | 0x100000;
  uVar1 = g_compile_flags_c4 & 0x20;
  g_compile_flags_c4 = uVar3;
  if (uVar1 != 0) {
    il_emit_pragma_or_segment_record(0x24);
  }
  if ((sym->flags4 & 0x40) != 0) {
    bVar2 = sym->kind & 0x1f;
    if (bVar2 == 3) {
      sym = sym_static_member_stand_in(sym);
    }
    else if (bVar2 == 10) {
      sym = sym_inline_instance_of(sym);
    }
    else {
      sym = (c1_symbol *)0x0;
    }
  }
  sym->flags3 = sym->flags3 | 0x20;
  if ((sym->flags23 & 1) != 0) {
    pcVar4 = sym_segment_record(sym);
    if ((pcVar4->x28).bytes.bit_position == '\x04') {
      sym->flags23 = sym->flags23 & 0xfe;
    }
  }
  if ((g_bss_seg_name != (void *)0x0) && (((sym->flags23 & 1) == 0 || ((sym->flags23 & 2) != 0)))) {
    if (g_bss_seg_name == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym,g_bss_seg_name);
    }
    sym->flags23 = sym->flags23 | 2;
  }
  if ((sym->flags22 & 0x40) != 0) {
    diag_error(0x1f0,sym);
    sym->flags22 = sym->flags22 & 0xbf;
    sym->storage = sym->storage & 0xbf;
    sym->flags21 = sym->flags21 & 0x7f;
  }
  return;
}

