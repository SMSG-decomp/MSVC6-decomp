byte __cdecl
tmpl_check_arguments(c1_symbol *tmpl,c1_sym_list *param_list,c1_arg_list **args,uint unused4)

{
  c1_u32 *pcVar1;
  c1_u8 cVar2;
  c1_u16 cVar3;
  c1_node *pcVar4;
  uint uVar5;
  uint uVar6;
  c1_u8 *pcVar7;
  byte bVar8;
  char cVar9;
  ushort uVar10;
  char *pcVar11;
  c1_node *pcVar12;
  c1_symbol_type_word cVar13;
  c1_type *pcVar14;
  c1_type *pcVar15;
  c1_arg_item *pcVar16;
  int iVar17;
  byte local_29;
  c1_sym_link *local_24;
  c1_type local_20;
  c1_type local_10;
  
  pcVar16 = (*args)->first;
  iVar17 = 0;
  local_29 = 1;
  if (param_list == (c1_sym_list *)0x0) {
    local_24 = (c1_sym_link *)0x0;
  }
  else {
    local_24 = param_list->head;
  }
  if (local_24 == (c1_sym_link *)0x0) {
    return 1;
  }
  do {
    pcVar1 = &local_24[-1].position;
    if (pcVar16 == (c1_arg_item *)0x0) {
      return local_29;
    }
    iVar17 = iVar17 + 1;
    bVar8 = pcVar16->kind & 3;
    if (bVar8 == 0) {
      if ((*pcVar1 & 0x1f) == 0x16) {
        pcVar14 = (pcVar16->value).type;
        uVar10 = tmpl_type_find_parameter(pcVar14,0,0);
        if (uVar10 == 0) {
          cVar9 = type_has_linkage_for_template(pcVar14);
          if (cVar9 == '\0') {
            diag_error(0x39e,(pcVar16->value).type);
            (pcVar16->value).type = g_type_int;
            local_29 = 0;
          }
        }
        else if ((pcVar14->code & 0xfff) == 0x802) {
          cVar13 = local_24->type;
          goto LAB_10424e5d;
        }
      }
      else {
        if ((g_compile_flags_cc & 0x100000) == 0) {
          local_29 = 0;
          diag_error(0x3cf,tmpl,pcVar1);
        }
        pcVar7 = g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + 0x18;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        pcVar7[0x10] = '\0';
        pcVar7[0x11] = '\0';
        pcVar7[0x12] = '\0';
        pcVar7[0x13] = '\0';
        pcVar7[1] = 0x83;
        *pcVar7 = 'e';
        pcVar7[0x14] = '\0';
        pcVar7[0x15] = '\0';
        pcVar7[0x16] = '\0';
        pcVar7[0x17] = '\0';
        *(c1_type **)(pcVar7 + 4) = g_type_int;
        pcVar16->kind = pcVar16->kind & 0xfc ^ 1;
        if (pcVar7 == (c1_u8 *)0x0) {
LAB_104b8233:
          cVar13.type = (c1_type *)0x0;
        }
        else {
          cVar13.type = (c1_type *)tree_copy_to_arena((c1_node *)pcVar7,0);
        }
LAB_10424e5d:
        pcVar16->value = (c1_arg_value)cVar13;
      }
    }
    else if (bVar8 == 1) {
      if ((*pcVar1 & 0x1f) == 0x16) {
        local_29 = 0;
        if ((((pcVar16->value).expr)->kind & 7) == 4) {
          diag_error(0x39b,tmpl,((pcVar16->value).expr)->left,iVar17);
        }
        else {
          diag_error(0x3ce,tmpl,pcVar1);
        }
        pcVar16->kind = pcVar16->kind & 0xfc;
        (pcVar16->value).type = g_type_int;
      }
      else {
        pcVar12 = (pcVar16->value).expr;
        pcVar11 = tree_find_template_parameter_use((char *)pcVar12);
        if (pcVar11 == (char *)0x0) {
          pcVar14 = (local_24->type).type;
          uVar10 = tmpl_type_find_parameter(pcVar14,1,0);
          if ((uVar10 != 0) &&
             (pcVar15 = tmpl_substitute_type(pcVar14,*args), pcVar15 != (c1_type *)0x0)) {
            pcVar14 = pcVar15;
          }
          if (((char)pcVar14->code < '\0') &&
             ((uVar10 = pcVar14->code & 0x8f, uVar10 == 0x86 || (uVar10 == 0x82)))) {
            cVar2 = pcVar12->op;
            pcVar4 = pcVar12;
            while (cVar2 == 'd') {
              pcVar4 = pcVar4->left;
              cVar2 = pcVar4->op;
            }
            if ((((pcVar4->op == '=') && (*(char *)pcVar4->left == '\x06')) &&
                (bVar8 = **(byte **)((int)pcVar4->left + 0x10) & 0x1f, bVar8 != 0x12)) &&
               (bVar8 != 0x17)) {
              diag_error(0x3cf,tmpl,&local_24[-1].position);
              local_29 = 0;
            }
          }
          pcVar12 = conv_convert_expression(0xf1,pcVar14,pcVar12,'\x02','\b');
          if (pcVar12 != (c1_node *)0x0) {
            if (pcVar12->op == 'd') {
              pcVar14 = pcVar12->type;
              pcVar15 = *(c1_type **)((int)pcVar12->left + 4);
              if ((pcVar14->flags & 0x20) != 0) {
                uVar5._0_2_ = pcVar14->code;
                uVar5._2_2_ = pcVar14->flags;
                local_20.base = pcVar14->base;
                local_20.extra = pcVar14->extra;
                local_20._0_4_ = uVar5 & 0xffdfffff;
                local_20.debug_index = pcVar14->debug_index;
                pcVar14 = type_intern(&local_20);
              }
              if ((pcVar15->flags & 0x20) != 0) {
                local_10.base = pcVar15->base;
                uVar6._0_2_ = pcVar15->code;
                uVar6._2_2_ = pcVar15->flags;
                local_10.extra = pcVar15->extra;
                local_10.debug_index = pcVar15->debug_index;
                local_10._0_4_ = uVar6 & 0xffdfffff;
                pcVar15 = type_intern(&local_10);
              }
              if (pcVar14 == pcVar15) {
                pcVar12 = pcVar12->left;
              }
            }
            if (((pcVar12 != (c1_node *)0x0) && (cVar3 = pcVar12->type->code, cVar3 != 0x80c)) &&
               (cVar3 != 0x80e)) {
              cVar13.type = (c1_type *)tree_copy_to_arena(pcVar12,0);
              goto LAB_10424e5d;
            }
          }
          local_29 = 0;
          diag_error(0x3cf,tmpl,&local_24[-1].position);
          pcVar7 = g_arenas[0].cur;
          g_arenas[0].cur = g_arenas[0].cur + 0x18;
          if (g_arenas[0].end < g_arenas[0].cur) {
            arena_grow(g_arenas);
          }
          pcVar7[0x10] = '\0';
          pcVar7[0x11] = '\0';
          pcVar7[0x12] = '\0';
          pcVar7[0x13] = '\0';
          pcVar7[1] = 0x83;
          *pcVar7 = 'e';
          pcVar7[0x14] = '\0';
          pcVar7[0x15] = '\0';
          pcVar7[0x16] = '\0';
          pcVar7[0x17] = '\0';
          *(c1_type **)(pcVar7 + 4) = g_type_int;
          pcVar16->kind = pcVar16->kind & 0xfc ^ 1;
          if (pcVar7 == (c1_u8 *)0x0) goto LAB_104b8233;
          cVar13.type = (c1_type *)tree_copy_to_arena((c1_node *)pcVar7,0);
          goto LAB_10424e5d;
        }
        if (*pcVar11 == '\x06') {
          if ((*(int *)(pcVar11 + 0x10) != 0) && (*(int *)(*(int *)(pcVar11 + 0x10) + 0x2c) != 0)) {
LAB_10424e86:
            if ((c1_node *)local_24[2].next == (c1_node *)0x0) goto LAB_104b8233;
            cVar13.type = (c1_type *)tree_copy_to_arena((c1_node *)local_24[2].next,0);
            goto LAB_10424e5d;
          }
        }
        else if (*pcVar11 == 'e') goto LAB_10424e86;
      }
    }
    pcVar16 = pcVar16->next;
    if (local_24 == (c1_sym_link *)0x0) {
      return local_29;
    }
    local_24 = local_24->next;
    if (local_24 == (c1_sym_link *)0x0) {
      return local_29;
    }
  } while( true );
}

