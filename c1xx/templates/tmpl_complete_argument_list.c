byte __cdecl
tmpl_complete_argument_list(c1_symbol *tmpl,c1_sym_list *params,c1_arg_list **args,uint *count)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_sym_link *pcVar3;
  int *piVar4;
  c1_arg_item *pcVar5;
  c1_node *pcVar6;
  c1_arg_item *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  c1_arg_list *pcVar11;
  int arena;
  byte local_9;
  int local_8;
  c1_arg_item *local_4;
  uint word_2;
  uint word;
  
  uVar9 = 0;
  local_9 = 1;
  if (params == (c1_sym_list *)0x0) {
    pcVar3 = (c1_sym_link *)0x0;
  }
  else {
    pcVar3 = params->head;
  }
  for (; (pcVar3 != (c1_sym_link *)0x0 && (uVar9 = uVar9 + 1, pcVar3 != (c1_sym_link *)0x0));
      pcVar3 = pcVar3->next) {
  }
  if (*args != (c1_arg_list *)0x0) {
    for (pcVar5 = (*args)->first; pcVar5 != (c1_arg_item *)0x0; pcVar5 = pcVar5->next) {
      *count = *count + 1;
    }
  }
  uVar10 = *count;
  if (uVar10 >= uVar9 && uVar10 != uVar9) {
    diag_error(0x3d1,tmpl);
    pcVar5 = (*args)->first;
    if (1 < uVar9) {
      iVar8 = uVar9 - 1;
      do {
        pcVar5 = pcVar5->next;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    pcVar5->next = (c1_arg_item *)0x0;
    return 0;
  }
  if (uVar10 < uVar9) {
    uVar9 = uVar9 - uVar10;
    uVar10 = 0;
    piVar4 = tmpl_default_arguments_lookup(tmpl);
    if (piVar4 != (int *)0x0) {
      for (iVar8 = *piVar4; iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        uVar10 = uVar10 + 1;
      }
    }
    if (uVar10 < uVar9) {
      if ((tmpl->kind & 0x1f) == 4) {
        diag_error(0x3d0,tmpl);
        local_9 = 0;
        pcVar11 = (c1_arg_list *)0x0;
        pcVar5 = (c1_arg_item *)g_arenas[5].cur;
        for (iVar8 = uVar9 - uVar10; iVar8 != 0; iVar8 = iVar8 + -1) {
          g_arenas[5].cur = (c1_u8 *)&pcVar5->value;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar5 == (c1_arg_item *)0x0) {
            pcVar5 = (c1_arg_item *)0x0;
          }
          else {
            pcVar5->next = (c1_arg_item *)0x0;
            pcVar5->prev = (c1_arg_item *)0x0;
            pcVar5->vtbl = &PTR_pch_mark_object_links_104cf060;
            pcVar5->kind = pcVar5->kind & 0xf8 ^ 2;
          }
          pcVar1 = g_arenas[5].cur;
          if (pcVar11 == (c1_arg_list *)0x0) {
            g_arenas[5].cur = g_arenas[5].cur + 0xc;
            if (g_arenas[5].end < g_arenas[5].cur) {
              arena_grow(g_arenas + 5);
            }
            if (pcVar1 == (c1_u8 *)0x0) {
              pcVar11 = (c1_arg_list *)0x0;
            }
            else {
              *(c1_arg_item **)pcVar1 = pcVar5;
              *(c1_arg_item **)(pcVar1 + 4) = pcVar5;
              bVar2 = (pcVar5->kind >> 3 & 1 ^ pcVar1[8]) & 1 ^ pcVar1[8];
              pcVar11 = (c1_arg_list *)pcVar1;
LAB_104b7e75:
              pcVar11->flags = bVar2;
            }
          }
          else {
            pcVar5->next = pcVar11->first;
            pcVar11->first->prev = pcVar5;
            pcVar11->first = pcVar5;
            if ((pcVar5->kind & 8) != 0) {
              bVar2 = pcVar11->flags | 1;
              goto LAB_104b7e75;
            }
          }
          pcVar5 = (c1_arg_item *)g_arenas[5].cur;
        }
        g_arenas[5].cur = (c1_u8 *)pcVar5;
        if (*args != (c1_arg_list *)0x0) {
          pcVar5 = (*args)->last;
          pcVar5->next = pcVar11->first;
          pcVar11->first->prev = pcVar5;
          return 0;
        }
        *args = pcVar11;
      }
    }
    else {
      iVar8 = *piVar4;
      uVar10 = uVar9;
      while (uVar10 = uVar10 - 1, uVar10 != 0) {
        iVar8 = *(int *)(iVar8 + 4);
      }
      if (*args == (c1_arg_list *)0x0) {
        local_8 = 0;
        pcVar5 = (c1_arg_item *)args;
        if (iVar8 != 0) {
          do {
            pcVar1 = g_arenas[0].cur;
            bVar2 = *(byte *)(iVar8 + 0xc) & 3;
            if (bVar2 == 1) {
              pcVar6 = *(c1_node **)(iVar8 + 0x10);
              if (pcVar6->op == 0xc6) {
                if (*args != (c1_arg_list *)0x0) {
                  tmpl_check_arguments(tmpl,params,args,*count);
                }
                pcVar7 = tmpl_evaluate_default_argument(tmpl,params,*args,pcVar6,local_8);
                if (pcVar7 != (c1_arg_item *)0x0) {
                  pcVar5 = pcVar7;
                }
              }
              else {
                g_arenas[0].cur = g_arenas[0].cur + 0x14;
                if (g_arenas[0].end < g_arenas[0].cur) {
                  arena_grow(g_arenas);
                }
                if (pcVar1 == (c1_u8 *)0x0) {
LAB_104b7d8a:
                  pcVar5 = (c1_arg_item *)0x0;
                }
                else {
                  pcVar1[4] = '\0';
                  pcVar1[5] = '\0';
                  pcVar1[6] = '\0';
                  pcVar1[7] = '\0';
                  pcVar1[8] = '\0';
                  pcVar1[9] = '\0';
                  pcVar1[10] = '\0';
                  pcVar1[0xb] = '\0';
                  *(undefined ***)pcVar1 = &PTR_pch_fixup_tree_list_object_104bcbcc;
                  pcVar1[0xc] = pcVar1[0xc] & 0xf8 ^ 1;
                  *(c1_node **)(pcVar1 + 0x10) = pcVar6;
                  pcVar5 = (c1_arg_item *)pcVar1;
                }
              }
            }
            else if (bVar2 == 0) {
              g_arenas[0].cur = g_arenas[0].cur + 0x14;
              if (g_arenas[0].end < g_arenas[0].cur) {
                arena_grow(g_arenas);
              }
              if (pcVar1 == (c1_u8 *)0x0) goto LAB_104b7d8a;
              word_2 = *(uint *)(iVar8 + 0x10);
              pcVar1[4] = '\0';
              pcVar1[5] = '\0';
              pcVar1[6] = '\0';
              pcVar1[7] = '\0';
              pcVar1[8] = '\0';
              pcVar1[9] = '\0';
              pcVar1[10] = '\0';
              pcVar1[0xb] = '\0';
              pcVar1[0xc] = pcVar1[0xc] & 0xf8;
              *(uint *)(pcVar1 + 0x10) = word_2;
              *(undefined ***)pcVar1 = &PTR_pch_fixup_list_object_104c4c3c;
              pcVar5 = (c1_arg_item *)pcVar1;
            }
            pcVar1 = g_arenas[0].cur;
            pcVar11 = *args;
            if (pcVar11 == (c1_arg_list *)0x0) {
              g_arenas[0].cur = g_arenas[0].cur + 0xc;
              if (g_arenas[0].end < g_arenas[0].cur) {
                arena_grow(g_arenas);
              }
              if (pcVar1 == (c1_u8 *)0x0) {
                *args = (c1_arg_list *)0x0;
              }
              else {
                *(c1_arg_item **)pcVar1 = pcVar5;
                *(c1_arg_item **)(pcVar1 + 4) = pcVar5;
                pcVar1[8] = (pcVar5->kind >> 3 & 1 ^ pcVar1[8]) & 1 ^ pcVar1[8];
                *args = (c1_arg_list *)pcVar1;
              }
            }
            else {
              pcVar11->last->next = pcVar5;
              pcVar5->prev = pcVar11->last;
              pcVar11->last = pcVar5;
              if ((pcVar5->kind & 8) != 0) {
                pcVar11->flags = pcVar11->flags | 1;
              }
            }
            iVar8 = *(int *)(iVar8 + 8);
            local_8 = local_8 + 1;
            if (iVar8 == 0) {
              return 1;
            }
          } while( true );
        }
      }
      else {
        uVar10 = 0;
        local_4 = (*args)->last;
        if (uVar9 != 0) {
          do {
            pcVar5 = (c1_arg_item *)g_arenas[0].cur;
            bVar2 = *(byte *)(iVar8 + 0xc) & 3;
            if (bVar2 == 1) {
              pcVar6 = *(c1_node **)(iVar8 + 0x10);
              if (pcVar6->op == 0xc6) {
                if (*args != (c1_arg_list *)0x0) {
                  tmpl_check_arguments(tmpl,params,args,*count);
                }
                pcVar5 = tmpl_evaluate_default_argument(tmpl,params,*args,pcVar6,*count + uVar10);
                if (pcVar5 == (c1_arg_item *)0x0) {
                  pcVar5 = arena_alloc(g_arenas,0x14);
                  if (pcVar5 != (c1_arg_item *)0x0) goto LAB_104b7b30;
LAB_104b7c05:
                  pcVar5 = (c1_arg_item *)0x0;
                }
              }
              else {
                pcVar5 = arena_alloc(g_arenas,0x14);
                if (pcVar5 == (c1_arg_item *)0x0) goto LAB_104b7c05;
                (pcVar5->value).expr = pcVar6;
                pcVar5->next = (c1_arg_item *)0x0;
                pcVar5->prev = (c1_arg_item *)0x0;
                pcVar5->kind = pcVar5->kind & 0xf8 ^ 1;
                pcVar5->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
              }
            }
            else if (bVar2 == 0) {
              g_arenas[0].cur = g_arenas[0].cur + 0x14;
              if (g_arenas[0].end < g_arenas[0].cur) {
                arena_grow(g_arenas);
              }
              if (pcVar5 == (c1_arg_item *)0x0) goto LAB_104b7c05;
              bVar2 = *(byte *)((int)pcVar5 + 0xc);
              word = *(uint *)(iVar8 + 0x10);
              *(c1_u8 *)((int)pcVar5 + 4) = '\0';
              *(c1_u8 *)((int)pcVar5 + 5) = '\0';
              *(c1_u8 *)((int)pcVar5 + 6) = '\0';
              *(c1_u8 *)((int)pcVar5 + 7) = '\0';
              *(c1_u8 *)((int)pcVar5 + 8) = '\0';
              *(c1_u8 *)((int)pcVar5 + 9) = '\0';
              *(c1_u8 *)((int)pcVar5 + 10) = '\0';
              *(c1_u8 *)((int)pcVar5 + 0xb) = '\0';
              *(byte *)((int)pcVar5 + 0xc) = bVar2 & 0xf8;
              *(uint *)((int)pcVar5 + 0x10) = word;
              pcVar5->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
            }
            else {
              g_arenas[0].cur = g_arenas[0].cur + 0x14;
              if (g_arenas[0].end < g_arenas[0].cur) {
                arena_grow(g_arenas);
              }
              if (pcVar5 == (c1_arg_item *)0x0) goto LAB_104b7c05;
LAB_104b7b30:
              arena = 0;
              pcVar6 = tree_new_int_constant(0);
              pcVar6 = tree_copy_to_arena(pcVar6,arena);
              pcVar5->next = (c1_arg_item *)0x0;
              pcVar5->prev = (c1_arg_item *)0x0;
              pcVar5->kind = pcVar5->kind & 0xf8 ^ 1;
              pcVar5->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
              (pcVar5->value).expr = pcVar6;
            }
            uVar10 = uVar10 + 1;
            local_4->next = pcVar5;
            pcVar5->prev = local_4;
            iVar8 = *(int *)(iVar8 + 8);
            local_4 = pcVar5;
            if (uVar9 <= uVar10) {
              return 1;
            }
          } while( true );
        }
      }
    }
  }
  return local_9;
}

