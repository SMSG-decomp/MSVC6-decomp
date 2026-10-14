void __cdecl class_queue_special_member_definition(byte *key,c1_symbol *sym)

{
  c1_u8 *pcVar1;
  
  pcVar1 = class_special_member_parameters((int)key,(int)(char)(sym->tail).fn.special_kind,sym);
  g_pending_parameter_scope = *(c1_sym_list **)pcVar1;
  g_pending_function_word = *(int *)(pcVar1 + 0x10);
  class_synthesize_special_member_tokens((c1_symbol *)key,sym);
  return;
}

