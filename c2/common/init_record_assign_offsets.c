void __fastcall init_record_assign_offsets(c2_init *rec)

{
  int32_t iVar1;
  c2_init *rec_00;
  c2_fe_symbol *section;
  uint32_t uVar2;
  c2_fe_symbol *sym;
  int iVar3;
  
  sym = (rec->u18).sym;
  if ((((sym != (c2_fe_symbol *)0x0) ||
       (sym = fe_symbol_lookup_id((rec->u08).header.sym_id), sym != (c2_fe_symbol *)0x0)) &&
      ((sym->cls == '\x04' || (sym->cls == '\x01')))) && ((sym->storage & 0x1000) != 0)) {
    sym = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)sym);
  }
  if (rec->kind == 0) {
    section = fe_symbol_lookup_id(sym->section_id);
  }
  else {
    section = g_debug_types_section;
    if (rec->kind != 10) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x27b);
    }
  }
  iVar1 = section->offset;
  g_init_record_place_scratch = 0;
  rec_00 = rec;
  do {
    if (rec_00 == (c2_init *)0x0) {
      if (section != g_debug_types_section) {
        section->offset = iVar1;
      }
      (rec->u08).header.placed = 1;
      return;
    }
    if (rec_00->kind == 0) {
      iVar3 = (rec_00->u08).header.offset;
      uVar2 = sym->offset;
LAB_10750558:
      section->offset = iVar3 + uVar2;
    }
    else if (rec_00->kind != 10) {
      uVar2 = (*g_hook_emit_init_record)(rec_00,sym,section);
      iVar3 = section->offset;
      goto LAB_10750558;
    }
    rec_00 = rec_00->next;
  } while( true );
}

