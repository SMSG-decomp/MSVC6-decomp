int __fastcall type_is_register_candidate(uint16_t type)

{
  uint32_t uVar1;
  
  uVar1 = type_class_index(type);
  return (&g_float_fold_handler_table[4].op)[uVar1];
}

