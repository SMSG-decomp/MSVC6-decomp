c1xx_scope * __thiscall scope_innermost_declaration_record(c1_scope_stack *stack,char skip_binding)

{
  c1xx_scope *pcVar1;
  
  pcVar1 = stack->current;
  while ((0xfa < pcVar1->kind ||
         ((((pcVar1->kind == 0xfa && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
           (skip_binding != '\0')) && (g_tmpl_binding_in_progress == '\0'))))) {
    pcVar1 = pcVar1->outer;
  }
  return pcVar1;
}

