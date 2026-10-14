void __cdecl
sym_apply_specifier_block
          (c1_symbol *sym,uint storage_flags,void *segment,void *property,c1_guid *uuid)

{
  c1_u8 *value;
  
  sym->storage = (undefined1)storage_flags;
  sym->flags21 = storage_flags._1_1_;
  sym->flags22 = storage_flags._2_1_;
  sym->flags23 = storage_flags._3_1_;
  if (((storage_flags & 0x1000000) == 0) || (segment == (void *)0x0)) {
    sym->flags23 = sym->flags23 & 0xfe;
  }
  else {
    sym_set_segment(sym,segment);
  }
  value = g_arenas[0].cur;
  if (((storage_flags & 0x4000) == 0) || (uuid == (c1_guid *)0x0)) {
    sym->flags21 = sym->flags21 & 0xbf;
  }
  else {
    g_arenas[0].cur = g_arenas[0].cur + 0x10;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (value == (c1_u8 *)0x0) {
      sym_attach_extra(sym,(void *)0x0);
    }
    else {
      *(c1_u32 *)value = uuid->Data1;
      *(undefined4 *)(value + 4) = *(undefined4 *)&uuid->Data2;
      *(undefined4 *)(value + 8) = *(undefined4 *)uuid->Data4;
      *(undefined4 *)(value + 0xc) = *(undefined4 *)(uuid->Data4 + 4);
      sym_attach_extra(sym,value);
    }
  }
  if (property != (void *)0x0) {
    symtab_1b40_insert(sym,property);
    return;
  }
  sym->flags23 = sym->flags23 & 0x7f;
  return;
}

