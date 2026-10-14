c1_u8 * __thiscall
class_scope_lookup_by_kind(c1xx_class_scope *class_scope,int *name,uint flags,char *found)

{
  fe_name **ppfVar1;
  c1xx_block_scope *scope;
  c1_symbol *sym;
  bool bVar2;
  bool bVar3;
  c1_u8 *pcVar4;
  byte bVar5;
  c1_symbol *pcVar6;
  c1_u8 *pcVar7;
  int iVar8;
  c1_symbol *member;
  c1_sym_link *link;
  c1_sym_link *next_link;
  
  if ((flags & 0x400) != 0) {
    return (c1_u8 *)0x0;
  }
  pcVar6 = class_scope->cls;
  if ((pcVar6->kind & 0x1f) == 0x19) {
    pcVar7 = (c1_u8 *)(**(code **)(**(int **)pcVar6->type + 0x14))(name,flags,found);
    return pcVar7;
  }
  pcVar6 = class_lookup_member_set
                     (g_current_scope,pcVar6,name,flags,
                      (-(uint)(g_current_scope->reported != '\0') & 0xfffffe7f) + 0x181);
  if (pcVar6 == (c1_symbol *)0x0) {
    if (class_scope->reached == '\0') {
      *found = '\0';
    }
    scope = class_scope->binding;
    if (scope == (c1xx_block_scope *)0x0) {
      return (c1_u8 *)0x0;
    }
    pcVar7 = (*scope->vtbl->lookup_by_kind)(scope,(int)name,flags,(byte *)found);
    return pcVar7;
  }
  if (*found == '\0') {
    if (class_scope->reached != '\0') goto LAB_10431456;
  }
  else if (class_scope->reached != '\0') {
    if ((**(byte **)(*(int *)pcVar6->type + 8) & 0x1f) != 4) {
      pcVar6->flags1 = pcVar6->flags1 | 0x80;
    }
    goto LAB_10431456;
  }
  if (class_scope->kind != 0xfc) {
    sym = *(c1_symbol **)(*(int *)pcVar6->type + 8);
    bVar5 = sym->kind & 0x1f;
    if (((((bVar5 != 3) || ((sym->storage & 7) != 3)) && (bVar5 != 5)) &&
        (((sym->flags2 & 0x10) == 0 && (bVar5 != 0xf)))) &&
       ((bVar5 != 0x1a && ((class_scope->cls != sym && (g_current_scope->current->kind != '\x01'))))
       )) {
      if ((bVar5 == 0x11) || (bVar5 == 8)) {
        ppfVar1 = &sym->name;
        bVar3 = false;
        bVar2 = false;
        if (ppfVar1 != (fe_name **)0x0) {
          iVar8 = sym_is_data_or_function_2(sym);
          link = (c1_sym_link *)ppfVar1;
          bVar2 = bVar3;
          if (((char)iVar8 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
            link = (c1_sym_link *)sym->type;
          }
          while ((ppfVar1 != (fe_name **)0x0 && (link != (c1_sym_link *)0x0))) {
            iVar8 = sym_is_data_or_function_2(sym);
            if (((char)iVar8 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
              next_link = link->next;
            }
            else {
              next_link = (c1_sym_link *)0x0;
            }
            member = (c1_symbol *)&link[-1].position;
            if ((link[-1].position & 0x1f) == 0x1a) {
              member = ((link->type).alias)->target;
            }
            link = next_link;
            if ((*(byte *)((int)&member->tail + 8) & 1) == 0) {
              link = next_link;
              bVar2 = true;
            }
          }
        }
        if (!bVar2) goto joined_r0x104930a2;
      }
      else if ((sym->flags2 & 0x40) == 0) {
joined_r0x104930a2:
        if ((g_compile_flags_c4 & 0x10000000) != 0) {
          return (c1_u8 *)0x0;
        }
        diag_error(0x147,pcVar6);
        return (c1_u8 *)0x0;
      }
    }
  }
LAB_10431456:
  pcVar7 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 8;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar4 = g_arenas[5].cur;
  if (pcVar7 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar4 != (c1_u8 *)0x0) {
    *(c1_symbol **)pcVar4 = pcVar6;
    *(c1xx_class_scope **)(pcVar4 + 4) = class_scope;
    pcVar4[8] = '\0';
    pcVar4[9] = '\0';
    pcVar4[10] = '\0';
    pcVar4[0xb] = '\0';
    *(c1_u8 **)pcVar7 = pcVar4;
    *(c1_u8 **)(pcVar7 + 4) = pcVar4;
    return pcVar7;
  }
  pcVar7[0] = '\0';
  pcVar7[1] = '\0';
  pcVar7[2] = '\0';
  pcVar7[3] = '\0';
  pcVar7[4] = '\0';
  pcVar7[5] = '\0';
  pcVar7[6] = '\0';
  pcVar7[7] = '\0';
  return pcVar7;
}

