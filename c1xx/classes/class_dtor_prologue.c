void __cdecl class_dtor_prologue(c1_symbol *cls)

{
  c1_u32 *sym;
  byte bVar1;
  c1_node *object;
  c1_node *name;
  int iVar2;
  c1_symbol *cls_00;
  c1_type *target;
  c1_node *pcVar3;
  c1_sym_link *pcVar4;
  
  if (((((cls->detail).cls)->implicit_state42 & 0x10) == 0) &&
     (class_note_vtable_built(cls), (((cls->detail).cls)->layout_flags3c & 0x80) == 0)) {
    class_mark_used_and_count_vbases(cls,(c1_symbol *)0x1);
  }
  eh_push_state();
  object = expr_this_pointer((c1_symbol *)0x0);
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar4 = (c1_sym_link *)0x0;
  }
  else {
    pcVar4 = ((cls->x28).members)->head;
  }
  for (; pcVar4 != (c1_sym_link *)0x0; pcVar4 = pcVar4->next) {
    sym = &pcVar4[-1].position;
    bVar1 = (byte)pcVar4[-1].position & 0x1f;
    if (bVar1 == 0xf) {
      if (((uint)pcVar4[1].name & 0x10000) == 0) {
        cls_00 = g_scope_vector->entries[*(short *)&pcVar4[1].name];
        access_set_special_member_context('\x01');
        goto LAB_1041b1d9;
      }
    }
    else if ((((bVar1 == 3) && (pcVar4->name != g_name_alignment_member)) &&
             (iVar2 = sym_is_static_data_member((c1_symbol *)sym), iVar2 == 0)) &&
            (cls_00 = sym_class_type_of((c1_symbol *)sym), cls_00 != (c1_symbol *)0x0)) {
LAB_1041b1d9:
      if (((pcVar4[1].position & 0x80000000) == 0) &&
         ((((cls_00->detail).cls)->implicit_state41 & 0x10) == 0)) {
        if ((*sym & 0x1f) == 0xf) {
          target = type_this_pointer(cls_00,(byte)object->type->flags & 0x18,0);
          pcVar3 = conv_convert_expression('d',target,object,'\x02','\0');
          pcVar3 = expr_build_destructor_call(cls_00,pcVar3,1,1,0);
        }
        else {
          pcVar3 = expr_prepare_member_access_object(g_current_scope,'S',object,'\x01');
          name = expr_lookup_name_expression(pcVar4->name);
          pcVar3 = expr_build_member_access('S',pcVar3,name);
          if ((((pcVar4->type).type)->code & 0x8f) == 0x83) {
            pcVar3 = expr_array_destroy_elements(pcVar3);
          }
          else {
            pcVar3 = expr_build_address_of(pcVar3,4);
            pcVar3 = expr_build_destructor_call(cls_00,pcVar3,3,1,0);
          }
        }
        if (pcVar3 != (c1_node *)0x0) {
          pcVar3 = expr_build_eh_state_update((c1_node *)0x0,pcVar3,cls);
          stmt_emit_expression(pcVar3);
        }
      }
    }
    access_set_special_member_context('\0');
    if (pcVar4 == (c1_sym_link *)0x0) break;
  }
  eh_pop_state();
  return;
}

