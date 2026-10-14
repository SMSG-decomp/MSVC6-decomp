c1_node * __cdecl
expr_check_call_context_tail
          (c1_node *vfptr,c1_node *thisarg,c1_symbol *sym,c1_node *call,char object_first,
          void *visitor_vtable,int visitor_mask,c1_node *object,int nonvirtual)

{
  c1_node *left;
  char cVar1;
  c1_node *right;
  
  if (g_minimal_rebuild_tracker->current->tracked != '\0') {
    mre_note_class_use(g_minimal_rebuild_tracker,(c1_symbol *)nonvirtual);
  }
  if ((sym->flags1 & 0x10) == 0x10) {
    call->type = (c1_type *)
                 **(undefined4 **)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
  }
  thisarg->kind = '\x02';
  thisarg->right = vfptr;
  thisarg->type = sym->type;
  call->left = thisarg;
  right = expr_build_call_with_temporaries
                    (call,sym,*(ushort *)((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)))
  ;
  left = object;
  if ((object_first != '\0') && (object != (c1_node *)0x0)) {
    visitor_mask = 0xff;
    visitor_vtable = &g_side_effect_visitor_vtable;
    cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor_vtable,object);
    if (cVar1 != '\0') {
      right = tree_new_binary_typed_right('7',left,right);
    }
  }
  return right;
}

