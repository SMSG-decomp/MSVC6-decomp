char __thiscall
tmpl_unify_types(c1_tmpl_deduction *deduction,c1_type *type,c1_type *type2,char top_level)

{
  c1_deferred_detail cVar1;
  c1_type_list *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  byte bVar5;
  ushort uVar8;
  c1_deferred_action *binding;
  c1_type *top_arg_type;
  char cVar6;
  byte bVar7;
  c1_u8 *pcVar9;
  c1_deferred_action *binding_3;
  c1_symbol *pcVar10;
  c1_symbol *pcVar11;
  byte bVar12;
  c1_type **ppcVar13;
  int *piVar14;
  c1_type **ppcVar15;
  c1_deferred_action *binding_4;
  c1_deferred_action *binding_2;
  bool bVar16;
  c1_member_iter member_iter;
  c1_type *top_arg_type_2;
  c1_type *top_arg_type_3;
  c1_type *top_arg_type_4;
  c1_type_list *p_list;
  
  bVar7 = (byte)type2->code;
  if ((bVar7 >> 6 & 1) != 0) {
    if (((byte)type->code >> 6 & 1) != 0) {
      diag_fatal(1,"..\\Cxx\\dymto.c",0x13a5);
    }
    binding = arena_alloc(g_arenas + 5,0x14);
    if (binding == (c1_deferred_action *)0x0) {
      binding = (c1_deferred_action *)0x0;
    }
    else {
      cVar1 = (c1_deferred_detail)deduction->arg_type;
      top_arg_type_2 = deduction->param_type;
      pcVar10 = deduction->tmpl;
      binding->next = (c1_deferred_action *)0x0;
      binding->sym = pcVar10;
      binding->arg = top_arg_type_2;
      binding->detail = cVar1;
      binding->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
    }
    if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
      g_deferred_actions_head = binding;
      g_deferred_actions_tail = binding;
      return '\0';
    }
LAB_104a85af:
    g_deferred_actions_tail->next = binding;
    g_deferred_actions_tail = binding;
    return '\0';
  }
  if ((deduction->flags & 0x10) == 0) {
    bVar5 = (byte)type->code;
    if (((char)bVar5 < '\0') && ((bVar5 & 0x8f) == 0x80)) {
      type = type_base(type);
    }
    else if ((bVar7 & 0x8f) == 0x83) {
      type2 = type_reference_to(type2,'\0');
    }
    else if ((bVar7 & 0x83) == 0x81) {
      type2 = type_member_pointer_to_2(type2,'\0');
    }
    else {
      type2 = type_strip_cv_qualifiers(type2);
    }
  }
  uVar8 = type->code;
  cVar6 = (char)uVar8;
  top_arg_type = type2;
  binding_4 = (c1_deferred_action *)g_arenas[5].cur;
  while (g_arenas[5].cur = (c1_u8 *)binding_4, cVar6 < '\0') {
    bVar7 = (byte)top_arg_type->code;
    if (-1 < (char)bVar7) {
      binding = arena_alloc(g_arenas + 5,0x14);
      if (binding == (c1_deferred_action *)0x0) {
        binding = (c1_deferred_action *)0x0;
        bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
      }
      else {
        cVar1 = (c1_deferred_detail)deduction->arg_type;
        pcVar3 = deduction->param_type;
        pcVar10 = deduction->tmpl;
        binding->next = (c1_deferred_action *)0x0;
        binding->sym = pcVar10;
        binding->arg = pcVar3;
        binding->detail = cVar1;
        binding->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
        bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
      }
LAB_104a89cd:
      if (bVar16) {
        g_deferred_actions_head = binding;
        g_deferred_actions_tail = binding;
        return '\0';
      }
      goto LAB_104a85af;
    }
    if ((((byte)uVar8 ^ bVar7) & 0x8f) != 0) {
      binding_3 = arena_alloc(g_arenas + 5,0x14);
      if (binding_3 == (c1_deferred_action *)0x0) {
        binding_3 = (c1_deferred_action *)0x0;
      }
      else {
        cVar1 = (c1_deferred_detail)deduction->arg_type;
        pcVar3 = deduction->param_type;
        pcVar10 = deduction->tmpl;
        binding_3->next = (c1_deferred_action *)0x0;
        binding_3->sym = pcVar10;
        binding_3->arg = pcVar3;
        binding_3->detail = cVar1;
        binding_3->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
      }
      if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
        g_deferred_actions_head = binding_3;
        g_deferred_actions_tail = binding_3;
        return '\0';
      }
      g_deferred_actions_tail->next = binding_3;
      g_deferred_actions_tail = binding_3;
      return '\0';
    }
    switch(uVar8 & 0x8f) {
    case 0x81:
    case 0x85:
      pcVar3 = ((type->extra).params)->this_type;
      if (pcVar3 == (c1_type *)0x0) {
LAB_104a87e6:
        p_list = ((type->extra).params)->list;
        pcVar2 = ((top_arg_type->extra).params)->list;
        type2 = (c1_type *)p_list->count;
        if (type2 == (c1_type *)pcVar2->count) {
          if (0 < (int)type2) {
            ppcVar15 = p_list->types;
            ppcVar13 = pcVar2->types;
            do {
              uVar8 = tmpl_type_find_parameter(*ppcVar15,1,0);
              if (uVar8 == 0) {
                if (*ppcVar15 != *ppcVar13) goto LAB_104a88a4;
              }
              else {
                cVar6 = tmpl_unify_types(deduction,*ppcVar15,*ppcVar13,'\x01');
                if (cVar6 == '\0') {
                  return '\0';
                }
              }
              ppcVar15 = ppcVar15 + 1;
              ppcVar13 = ppcVar13 + 1;
              type2 = (c1_type *)((int)&type2[-1].debug_index + 3);
            } while (0 < (int)type2);
          }
          break;
        }
        pcVar9 = g_arenas[5].cur + 0x14;
        binding_4 = (c1_deferred_action *)g_arenas[5].cur;
        g_arenas[5].cur = pcVar9;
        if (g_arenas[5].end < pcVar9) {
LAB_104a8ab7:
          arena_grow(g_arenas + 5);
        }
      }
      else {
        if (((top_arg_type->extra).params)->this_type != (c1_type *)0x0) {
          uVar8 = tmpl_type_find_parameter(pcVar3,1,0);
          if (uVar8 == 0) {
            if (((type->extra).params)->this_type != ((top_arg_type->extra).params)->this_type) {
              binding = arena_alloc(g_arenas + 5,0x14);
              if (binding == (c1_deferred_action *)0x0) {
                binding = (c1_deferred_action *)0x0;
              }
              else {
                cVar1 = (c1_deferred_detail)deduction->arg_type;
                pcVar3 = deduction->param_type;
                pcVar10 = deduction->tmpl;
                binding->next = (c1_deferred_action *)0x0;
                binding->sym = pcVar10;
                binding->arg = pcVar3;
                binding->detail = cVar1;
                binding->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
              }
              bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
              goto LAB_104a89cd;
            }
          }
          else {
            cVar6 = tmpl_unify_types(deduction,((type->extra).params)->this_type,
                                     ((top_arg_type->extra).params)->this_type,'\x01');
            if (cVar6 == '\0') {
              return '\0';
            }
          }
          goto LAB_104a87e6;
        }
        g_arenas[5].cur = (c1_u8 *)&binding_4->unk14;
        if (g_arenas[5].end < g_arenas[5].cur) goto LAB_104a8ab7;
      }
      if (binding_4 == (c1_deferred_action *)0x0) {
        binding_4 = (c1_deferred_action *)0x0;
        bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
      }
      else {
        cVar1 = (c1_deferred_detail)deduction->arg_type;
        pcVar3 = deduction->param_type;
        pcVar10 = deduction->tmpl;
        binding_4->next = (c1_deferred_action *)0x0;
        binding_4->sym = pcVar10;
        binding_4->arg = pcVar3;
        binding_4->detail = cVar1;
        binding_4->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
        bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
      }
LAB_104a8a6a:
      if (bVar16) {
        g_deferred_actions_head = binding_4;
        g_deferred_actions_tail = binding_4;
        return '\0';
      }
      g_deferred_actions_tail->next = binding_4;
      g_deferred_actions_tail = binding_4;
      return '\0';
    case 0x83:
      if ((type->extra).cls != (top_arg_type->extra).cls) {
LAB_104a88a4:
        pcVar9 = g_arenas[5].cur + 0x14;
        binding_4 = (c1_deferred_action *)g_arenas[5].cur;
        g_arenas[5].cur = pcVar9;
        if (g_arenas[5].end < pcVar9) {
LAB_104a88c1:
          arena_grow(g_arenas + 5);
        }
LAB_104a896c:
        if (binding_4 == (c1_deferred_action *)0x0) {
          binding_4 = (c1_deferred_action *)0x0;
        }
        else {
          cVar1 = (c1_deferred_detail)deduction->arg_type;
          pcVar3 = deduction->param_type;
          pcVar10 = deduction->tmpl;
          binding_4->next = (c1_deferred_action *)0x0;
          binding_4->sym = pcVar10;
          binding_4->arg = pcVar3;
          binding_4->detail = cVar1;
          binding_4->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
        }
        bVar16 = g_deferred_actions_head == (c1_deferred_action *)0x0;
        goto LAB_104a8a6a;
      }
      break;
    case 0x8a:
    case 0x8e:
      uVar8 = tmpl_type_find_parameter
                        (*(c1_type **)(*(int *)((-(uint)(cVar6 < '\0') & (uint)type) + 8) + 0x14),1,
                         0);
      if (uVar8 == 0) {
        if (*(int *)((-(uint)((type->code & 0x80) != 0) & (uint)type) + 8) !=
            *(int *)((-(uint)((top_arg_type->code & 0x80) != 0) & (uint)top_arg_type) + 8)) {
          pcVar9 = g_arenas[5].cur + 0x14;
          binding_4 = (c1_deferred_action *)g_arenas[5].cur;
          g_arenas[5].cur = pcVar9;
          if (g_arenas[5].end < pcVar9) goto LAB_104a88c1;
          goto LAB_104a896c;
        }
      }
      else {
        cVar6 = tmpl_unify_parameter
                          (deduction,
                           *(c1_type **)
                            (*(int *)((-(uint)((type->code & 0x80) != 0) & (uint)type) + 8) + 0x14),
                           *(c1_type **)
                            (*(int *)((-(uint)((top_arg_type->code & 0x80) != 0) &
                                      (uint)top_arg_type) + 8) + 0x14));
        if (cVar6 == '\0') {
          return '\0';
        }
      }
    }
    top_arg_type = type_base(top_arg_type);
    type = type_base(type);
    uVar8 = type->code;
    binding_4 = (c1_deferred_action *)g_arenas[5].cur;
    cVar6 = (char)uVar8;
  }
  uVar8 = tmpl_type_find_parameter(type,1,0);
  if (uVar8 == 0) {
    bVar5 = (byte)type->code;
    top_arg_type_3 = type;
    bVar7 = bVar5;
    while ((char)bVar7 < '\0') {
      top_arg_type_3 = top_arg_type_3->base;
      bVar7 = (byte)top_arg_type_3->code;
    }
    bVar12 = (byte)top_arg_type->code;
    top_arg_type_4 = top_arg_type;
    bVar7 = bVar12;
    while ((char)bVar7 < '\0') {
      top_arg_type_4 = top_arg_type_4->base;
      bVar7 = (byte)top_arg_type_4->code;
    }
    if ((((top_arg_type_4->code ^ top_arg_type_3->code) & 0xfff) == 0) &&
       ((type->extra).cls == (top_arg_type->extra).cls)) {
      return '\x01';
    }
    if (((((g_compile_flags_cc & 0x200000) == 0) ||
         (((type->code & 0x200) == 0 &&
          (((-1 < (char)bVar5 || ((bVar5 & 0x8f) != 0x80)) ||
           (type = type->base, (type->code & 0x200) == 0)))))) ||
        ((pcVar10 = (type->extra).cls, (top_arg_type->code & 0x200) == 0 &&
         (((-1 < (char)bVar12 || ((bVar12 & 0x8f) != 0x80)) ||
          (top_arg_type = top_arg_type->base, (top_arg_type->code & 0x200) == 0)))))) ||
       ((((((pcVar10->detail).cls)->flags3e & 2) == 0 ||
         ((((((top_arg_type->extra).cls)->detail).cls)->flags3e & 1) == 0)) ||
        (pcVar11 = tmpl_template_of_instance((top_arg_type->extra).cls), pcVar10 != pcVar11)))) {
      binding_2 = (c1_deferred_action *)g_arenas[5].cur;
      if (top_level != '\0') {
        g_arenas[5].cur = g_arenas[5].cur + 0x18;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (binding_2 == (c1_deferred_action *)0x0) {
          binding_2 = (c1_deferred_action *)0x0;
        }
        else {
          pcVar3 = deduction->arg_type;
          pcVar4 = deduction->param_type;
          pcVar10 = deduction->specialization;
          *(c1_symbol **)((int)binding_2 + 4) = deduction->tmpl;
          *(c1_u8 *)((int)binding_2 + 8) = '\0';
          *(c1_u8 *)((int)binding_2 + 9) = '\0';
          *(c1_u8 *)((int)binding_2 + 10) = '\0';
          *(c1_u8 *)((int)binding_2 + 0xb) = '\0';
          *(c1_symbol **)((int)binding_2 + 0xc) = pcVar10;
          *(c1_type **)((int)binding_2 + 0x10) = pcVar4;
          *(c1_type **)((int)binding_2 + 0x14) = pcVar3;
          binding_2->vtbl = &PTR_tmpl_deferred_report_c2785_104ceea0;
        }
        if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
          g_deferred_actions_head = binding_2;
          g_deferred_actions_tail = binding_2;
          return '\0';
        }
        g_deferred_actions_tail->next = binding_2;
        g_deferred_actions_tail = binding_2;
      }
      return '\0';
    }
  }
  else {
    cVar6 = tmpl_unify_parameter(deduction,type,top_arg_type);
    if (cVar6 == '\0') {
      if ((((deduction->flags & 0x10) == 0) &&
          ((deduction->cur_arg == (c1_arg_item *)0x0 || ((deduction->flags & 8) == 0)))) &&
         (((top_arg_type->code & 0x200) != 0 ||
          (((bVar7 = (byte)top_arg_type->code, (char)bVar7 < '\0' && ((bVar7 & 0x8f) == 0x80)) &&
           (top_arg_type = top_arg_type->base, (top_arg_type->code & 0x200) != 0)))))) {
        pcVar10 = (top_arg_type->extra).cls;
        if ((pcVar10->flags2 & 4) == 0) {
          tmpl_instantiate_if_needed(pcVar10);
        }
        class_member_iter_init(&member_iter,&pcVar10->name,4);
        piVar14 = member_iter.cursor.current;
        do {
          while( true ) {
            member_iter.current = member_iter.next;
            if (member_iter.current == (int *)0x0) goto LAB_104a878a;
            if ((piVar14 == (int *)0x0) ||
               (member_iter.next = (void *)piVar14[1], piVar14 = member_iter.next,
               member_iter.cursor.current = member_iter.next, member_iter.next == (int *)0x0)) {
              member_iter.next = (int *)0x0;
            }
            if ((*(byte *)((int)member_iter.current + -8) & 0x1f) == 3) break;
            if (((g_compile_flags_cc & 0x100000) == 0) ||
               (((*(byte *)((int)member_iter.current + -8) & 0x1f) != 0xf ||
                ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0)))) {
              if ((*(byte *)((int)member_iter.current + -8) & 0x1f) != 0xf) goto LAB_104a878a;
              deduction->flags = deduction->flags & 0xfb;
              if ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0) {
                pcVar10 = g_scope_vector->entries[(short)*(int *)((int)member_iter.current + 0x10)];
              }
              else {
                pcVar10 = (c1_symbol *)0x0;
              }
              cVar6 = tmpl_unify_types(deduction,type,pcVar10->type,'\x01');
              piVar14 = member_iter.cursor.current;
              if (cVar6 != '\0') {
                return '\x01';
              }
            }
          }
        } while ((*(void **)member_iter.current == g_name_vbptr) ||
                (*(void **)member_iter.current == g_name_vfptr));
      }
LAB_104a878a:
      deduction->flags = deduction->flags | 4;
      return '\0';
    }
  }
  return '\x01';
}

