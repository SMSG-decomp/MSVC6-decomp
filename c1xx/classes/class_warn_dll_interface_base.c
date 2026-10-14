c1_symbol * __cdecl class_warn_dll_interface_base(c1_symbol *base,int access,char is_virtual)

{
  c1_u8 cVar1;
  char cVar2;
  c1_symbol *pcVar3;
  int unaff_EBP;
  
  if (((((base->detail).cls)->layout_flags3c & 1) == 0) &&
     (cVar2 = class_is_pure_interface(base), unaff_EBP = g_class_depth, cVar2 == '\0')) {
    diag_warning(2,0x113,base->type,base,(g_class_def_stack[g_class_depth].cls)->type,
                 g_class_def_stack[g_class_depth].cls);
    unaff_EBP = g_class_depth;
  }
  cVar1 = class_check_duplicate_base(is_virtual,base,g_class_def_stack[unaff_EBP].cls);
  if (cVar1 == '\0') {
    return (c1_symbol *)0x0;
  }
  pcVar3 = class_append_base_entry(access,is_virtual,base);
  return pcVar3;
}

