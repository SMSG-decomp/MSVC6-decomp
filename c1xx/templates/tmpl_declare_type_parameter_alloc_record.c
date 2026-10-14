c1_symbol * __cdecl
tmpl_declare_type_parameter_alloc_record
          (undefined4 saved_ebp,undefined4 saved_ebx,c1_u16 proto_code,int zero)

{
  c1_symbol *pcVar1;
  c1_type *pcVar2;
  void *unaff_EBP;
  c1_u16 cStack0000000e;
  c1_type_extra cStack00000014;
  int in_stack_00000020;
  
  pcVar1 = sym_alloc_record(0x38,0x16,in_stack_00000020);
  if (pcVar1 == (c1_symbol *)zero) {
    pcVar1 = (c1_symbol *)0x0;
  }
  else {
    pcVar1 = sym_init_kind(pcVar1,'\x16',unaff_EBP,in_stack_00000020);
  }
  if (g_template_parameter_index != 0x40) {
    g_template_parameter_index = g_template_parameter_index + 1;
    cStack00000014 =
         (c1_type_extra)
         (int)(short)((ushort)(byte)g_template_depth << 8 | (ushort)g_template_parameter_index);
    proto_code = 0x801;
    cStack0000000e = (c1_u16)zero;
    pcVar2 = type_intern((c1_type *)&proto_code);
    pcVar1->type = pcVar2;
    pcVar1->flags2 = pcVar1->flags2 | 0x10;
    (*g_current_scope->current->vtbl->insert)(pcVar1);
    *(uint *)((int)unaff_EBP + 8) = *(uint *)((int)unaff_EBP + 8) | 0x20000;
    return pcVar1;
  }
  diag_fatal_simple(0x6f);
}

