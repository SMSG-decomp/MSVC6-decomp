c1_node * __cdecl expr_construct_result_in_place(c1_symbol *ctor,c1_node *object,c1_node *source)

{
  char cVar1;
  int eh_state;
  c1_node *pcVar2;
  void *visitor;
  int visitor_mask;
  
  pcVar2 = source;
  if (g_token_class[source->op] == '`') {
    pcVar2 = source->left;
  }
  visitor_mask = 0xff;
  visitor = &g_side_effect_visitor_vtable;
  cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor,object);
  if ((cVar1 == '\0') &&
     (*(char *)(*(int *)(((uint)ctor->type & -(uint)((ctor->type->code & 0x80) != 0)) + 8) + 4) ==
      '\0')) {
    cVar1 = expr_find_result_temporary(pcVar2,&source);
    if (cVar1 != '\0') {
      eh_state = eh_release_temporary_state((int)source->left);
      if (eh_state != -1) {
        pcVar2 = tree_copy_replacing_temporary(pcVar2,(int)source->left,object,eh_state);
        pcVar2 = tree_new_unary('=',g_scope_vector->entries[(short)ctor->scope_index]->type,pcVar2);
        return pcVar2;
      }
    }
  }
  return (c1_node *)0x0;
}

