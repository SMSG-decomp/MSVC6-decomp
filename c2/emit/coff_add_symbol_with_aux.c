uint32_t __fastcall
coff_add_symbol_with_aux
          (char *name,uint16_t section,char storage_class,int value,uint16_t type,void **aux_out,
          uint32_t key)

{
  uint32_t sym_index;
  c2_coff_slot *aux_slot;
  void *aux;
  
  if ((g_opt_incremental != 0) && (g_coff_reserved_slots_left == 0)) {
    coff_alloc_symbol_slots(2,section,0);
  }
  sym_index = coff_add_symbol(name,section,storage_class,value,type,key);
  *(char *)((int)g_coff_symbol_slots[sym_index]->payload + 0x11) =
       *(char *)((int)g_coff_symbol_slots[sym_index]->payload + 0x11) + '\x01';
  aux_slot = (*g_coff_alloc_fn)(0xc);
  aux_slot->kind = 4;
  aux = (*g_coff_alloc_fn)(0x12);
  aux_slot->payload = aux;
  *aux_out = aux;
  if (g_opt_incremental == 0) {
    coff_push_record(aux_slot);
    return sym_index;
  }
  coff_symtab_append(aux_slot);
  return sym_index;
}

