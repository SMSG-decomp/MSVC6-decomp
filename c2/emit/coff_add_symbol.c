uint32_t __fastcall
coff_add_symbol(char *name,uint16_t section,char storage_class,int value,uint16_t type,uint32_t key)

{
  int iVar1;
  uint16_t uVar2;
  c2_coff_slot *slot;
  c2_coff_symbol *sym;
  c2_coff_section *desc;
  uint32_t uVar3;
  bool bVar4;
  
  if ((g_coff_incremental_update != 0) && (key != 0)) {
    uVar3 = coff_hash64_find(key,section);
    if (uVar3 != 0) {
      sym = g_coff_symbol_slots[uVar3]->payload;
      if (section != 0) {
        if (g_coff_section_numbers_final == 0) {
          desc = coff_chunked_array_get(g_coff_sections,(uint)section);
          uVar2 = -desc->active->header_number - 2;
        }
        else {
          desc = coff_chunked_array_get(g_coff_sections,(uint)section);
          uVar2 = desc->active->header_number;
        }
        sym->section = uVar2;
      }
      sym->value = value;
      if ((section == 0) && (((byte)type & 0x30) == 0x20)) {
        coff_write_section_name(sym->short_name,name,0);
      }
      return uVar3;
    }
  }
  if ((g_opt_incremental != 0) && (g_coff_reserved_slots_left == 0)) {
    coff_alloc_symbol_slots(1,section,0);
  }
  slot = (*g_coff_alloc_fn)(0xc);
  sym = (*g_coff_alloc_fn)(0x12);
  bVar4 = section == g_coff_undef_section_id;
  sym->value = value;
  sym->storage_class = storage_class;
  if (bVar4) {
    sym->section = 0;
  }
  else if (section == g_coff_abs_section_id) {
    sym->section = -1;
  }
  else {
    if (g_coff_section_numbers_final == 0) {
      desc = coff_chunked_array_get(g_coff_sections,(uint)section);
      uVar2 = -desc->active->header_number - 2;
    }
    else {
      desc = coff_chunked_array_get(g_coff_sections,(uint)section);
      uVar2 = desc->active->header_number;
    }
    sym->section = uVar2;
  }
  sym->type = type;
  sym->naux = '\0';
  coff_write_section_name(sym->short_name,name,0);
  iVar1 = g_opt_incremental;
  slot->kind = 3;
  slot->payload = sym;
  slot->key = key;
  if (iVar1 == 0) {
    uVar3 = coff_push_record(slot);
    return uVar3;
  }
  uVar3 = coff_symtab_append(slot);
  return uVar3;
}

