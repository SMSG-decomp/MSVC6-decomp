uint32_t __fastcall
coff_add_global_symbol
          (uint32_t key,char *name,uint16_t section,char storage_class,int value,uint16_t type,
          int with_aux)

{
  uint32_t symbol_index;
  
  if (((short)with_aux == 0) || ((g_coff_line_info & 1) == 0)) {
    symbol_index = coff_add_symbol(name,section,storage_class,value,type,key);
    if ((g_opt_incremental != 0) && (g_incr_object_not_reusable == 0)) {
      g_coff_function_slot_mark = g_coff_reserved_slot_cursor - 1;
    }
  }
  else {
    symbol_index = coff_add_symbol_with_aux
                             (name,section,storage_class,value,type,(void **)&with_aux,key);
    if ((g_opt_incremental != 0) && (g_incr_object_not_reusable == 0)) {
      g_coff_line_symbol_slot = g_coff_reserved_slot_cursor;
      g_coff_function_slot_mark = g_coff_reserved_slot_cursor + 4;
      g_coff_reserved_slots_left = 0;
      g_coff_reserved_slot_cursor = 0;
      coff_hash32_resolve(key,symbol_index);
      return symbol_index;
    }
  }
  coff_hash32_resolve(key,symbol_index);
  return symbol_index;
}

