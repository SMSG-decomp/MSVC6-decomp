c1_node * __cdecl expr_build_member_access(c1_u8 op,c1_node *object,int name)

{
  char cVar1;
  char cVar2;
  c1_type *pcVar3;
  uint value;
  void *pvVar4;
  uint uVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  c1_node *pcVar8;
  c1_node *left;
  int *piVar9;
  fe_arena *a;
  c1_symbol *pcVar10;
  ushort uVar11;
  uint qualifiers;
  uint lvalue_flag;
  
  lvalue_flag = 0;
  if (object != (c1_node *)0x0) {
    pcVar7 = object->type;
    cVar1 = (char)pcVar7->code;
    pcVar3 = pcVar7;
    cVar2 = cVar1;
    while (cVar2 < '\0') {
      pcVar3 = pcVar3->base;
      cVar2 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0x200) == 0) {
      pcVar10 = (c1_symbol *)0x0;
    }
    else {
      pcVar10 = (pcVar3->extra).sym;
    }
    if ((pcVar3->code & 0x200) != 0) {
      if ((pcVar10->flags1 & 1) == 0) {
        diag_error(0x25,name,pcVar10);
        return (c1_node *)0x0;
      }
      if (pcVar10->tag_members == (void *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = *(int **)((int)pcVar10->tag_members + 4);
      }
      if (piVar9 != (int *)0x0) {
        while (*piVar9 != name) {
          if (piVar9 == (int *)0x0) goto LAB_106334cd;
          piVar9 = (int *)piVar9[1];
          if (piVar9 == (int *)0x0) {
            pcVar6 = expr_report_not_a_member();
            return pcVar6;
          }
        }
        if ((byte *)(piVar9 + -2) != (byte *)0x0) {
          value = piVar9[7];
          if (op == 'S') {
            uVar11 = pcVar7->code & 0x8f;
            if (((uVar11 != 0x82) && (uVar11 != 0x83)) || ((char)pcVar7->base->code < '\0')) {
              if (cVar1 < '\0') {
                diag_error(0xdf,*piVar9);
                return (c1_node *)0x0;
              }
              diag_error(0xe8,0x49,name,pcVar7);
              return (c1_node *)0x0;
            }
          }
          else if (cVar1 < '\0') {
            uVar11 = pcVar7->code & 0x8f;
            if (((uVar11 == 0x82) || (uVar11 == 0x83)) && (-1 < (char)pcVar7->base->code)) {
              diag_error(0xe7,0x49,name,pcVar7);
            }
            else {
              diag_error(0xe0,*piVar9);
            }
          }
          else {
            lvalue_flag = object->kind & 0x20;
            object = (c1_node *)expr_address_of_through_casts(object);
            if ((object->op == '4') && (-1 < (char)object->type->code)) {
              lvalue_flag = 1;
            }
          }
          pcVar7 = type_skip_arrays_and_functions(pcVar7);
          if ((char)pcVar7->code < '\0') {
            pcVar7 = pcVar7->base;
          }
          if ((pcVar7->code & 0x8f) == 0x83) {
            pcVar7 = type_skip_arrays(pcVar7->base);
          }
          qualifiers = pcVar7->flags & 0x2e0;
          if ((&g_token_class)[object->op] == -0x7d) {
            pvVar4 = object->right;
            uVar5 = *(uint *)((int)pvVar4 + 0x10);
            *(uint *)((int)pvVar4 + 0x10) = uVar5 + value;
            *(uint *)((int)pvVar4 + 0x14) =
                 *(int *)((int)pvVar4 + 0x14) + ((int)value >> 0x1f) + (uint)CARRY4(uVar5,value);
            pcVar6 = object;
          }
          else {
            a = g_arenas + g_expr_arena_index;
            pcVar6 = (c1_node *)a->cur;
            pcVar8 = (c1_node *)g_arenas[g_expr_arena_index].end;
            a->cur = &pcVar6[1].op;
            if (pcVar8 < pcVar6 + 1) {
              arena_grow(a);
            }
            pcVar6->kind = '\x02';
            pcVar6->op = op;
            pcVar6->left = object;
            pcVar8 = tree_new_int_constant(value);
            pcVar6->right = pcVar8;
          }
          pcVar7 = (c1_type *)piVar9[3];
          uVar11 = (ushort)qualifiers;
          pcVar6->type = pcVar7;
          if (uVar11 != 0) {
            pcVar7 = type_with_added_qualifiers(pcVar7,uVar11);
            pcVar6->type = pcVar7;
          }
          if ((*(byte *)(piVar9 + -1) & 4) == 0) {
            if ((*(byte *)(piVar9 + -2) & 0x1f) == 2) {
              pcVar8 = tree_new_int_constant((uint)*(byte *)((int)piVar9 + 0x21));
              left = tree_new_int_constant((uint)*(byte *)(piVar9 + 8));
              pcVar8 = tree_new_binary('6',left,pcVar8);
              pcVar6 = tree_new_binary('5',pcVar6,pcVar8);
              if (uVar11 != 0) {
                pcVar6 = expr_build_member_access_fragment(qualifiers,pcVar6,lvalue_flag);
                return pcVar6;
              }
            }
            pcVar6 = tree_new_rvalue(pcVar6);
            if (lvalue_flag == 0) {
              return pcVar6;
            }
            pcVar6->kind = pcVar6->kind | 0x20;
            return pcVar6;
          }
          return pcVar6;
        }
      }
LAB_106334cd:
      diag_error(0x27,0x49,name,pcVar10);
      return (c1_node *)0x0;
    }
    if (op == 'S') {
      diag_error(0xdf,name);
      return (c1_node *)0x0;
    }
    diag_error(0xe0,name);
  }
  return (c1_node *)0x0;
}

