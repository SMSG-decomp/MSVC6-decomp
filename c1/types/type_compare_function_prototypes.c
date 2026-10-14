c1_type * __cdecl
type_compare_function_prototypes
          (c1_type *new_type,c1_type *old_type,char outer,char recurse,int pass_through)

{
  byte bVar1;
  char cVar2;
  c1_type *pcVar3;
  bool bVar4;
  c1_type *pcVar5;
  uint uVar6;
  int iVar7;
  c1_param_list *pcVar8;
  int delta;
  int delta_2;
  uint *base_words;
  c1_type **ppcVar9;
  int *piVar10;
  undefined3 in_stack_0000000d;
  short n;
  c1_symbol *local_2c;
  c1_type *local_28;
  c1_param_list *local_24;
  int local_20;
  int local_1c;
  c1_type local_10;
  
  local_2c = (c1_symbol *)0x0;
  if (outer == '\0') {
    pcVar8 = (new_type->base->extra).params;
    local_24 = (old_type->base->extra).params;
    cVar2 = (char)new_type->code;
    pcVar5 = new_type;
    while (cVar2 < '\0') {
      pcVar5 = pcVar5->base;
      cVar2 = (char)pcVar5->code;
    }
    cVar2 = (char)old_type->code;
    pcVar3 = old_type;
    while (cVar2 < '\0') {
      pcVar3 = pcVar3->base;
      cVar2 = (char)pcVar3->code;
    }
    if ((pcVar5->code != pcVar3->code) || ((new_type->extra).sym != (old_type->extra).sym)) {
      return (c1_type *)0x0;
    }
  }
  else {
    bVar1 = (byte)new_type->code;
    pcVar5 = new_type;
    while ((bVar1 & 0x83) != 0x81) {
      pcVar5 = pcVar5->base;
      bVar1 = (byte)pcVar5->code;
    }
    bVar1 = (byte)old_type->code;
    local_28 = old_type;
    while ((bVar1 & 0x83) != 0x81) {
      local_28 = local_28->base;
      bVar1 = (byte)local_28->code;
    }
    pcVar8 = (pcVar5->extra).params;
    local_24 = (local_28->extra).params;
  }
  pcVar5 = (c1_type *)pcVar8->count;
  pcVar3 = (c1_type *)local_24->count;
  if (pcVar5 == (c1_type *)0x0) {
    new_type = old_type;
    if (pcVar3 == (c1_type *)0x0) {
      return old_type;
    }
LAB_10611d22:
    if (outer != '\0') {
      if (pcVar5 == (c1_type *)0x0) {
        pcVar8 = local_24;
      }
      ppcVar9 = pcVar8->types;
      delta = 1;
      iVar7 = (int)&pcVar3->code + (int)&pcVar5->code;
      if (0 < iVar7) {
        do {
          if ((*ppcVar9)->code == 0x80d) {
            return new_type;
          }
          pcVar5 = type_promoted_integral(*ppcVar9);
          if ((pcVar5 == (c1_type *)0x0) || (pcVar5 == *ppcVar9)) {
            pcVar5 = *ppcVar9;
            if (-1 < (char)pcVar5->code) {
              cVar2 = (char)pcVar5->code;
              while (cVar2 < '\0') {
                pcVar5 = pcVar5->base;
                cVar2 = (char)pcVar5->code;
              }
              if (pcVar5->code == 0x26) goto LAB_10637d93;
            }
          }
          else {
LAB_10637d93:
            if (g_ms_extensions == '\0') {
              diag_error(0x17b,delta);
            }
            else {
              diag_warning(4,0x20);
            }
          }
          ppcVar9 = ppcVar9 + 1;
          delta = delta + 1;
        } while (delta <= iVar7);
      }
    }
    return new_type;
  }
  if (pcVar3 == (c1_type *)0x0) goto LAB_10611d22;
  new_type = pcVar5;
  if (outer == '\0') {
    if (pcVar5 != pcVar3) {
      return (c1_type *)0x0;
    }
    goto LAB_10637aeb;
  }
  if ((int)pcVar3 < (int)pcVar5) {
    new_type = pcVar3;
    if (g_ms_extensions != '\0') {
      diag_warning(1,0x1e);
      goto LAB_10637aeb;
    }
    n = 0xbe;
  }
  else {
    if ((int)pcVar3 <= (int)pcVar5) goto LAB_10637aeb;
    if (g_ms_extensions != '\0') {
      diag_warning(1,0x1f);
      goto LAB_10637aeb;
    }
    n = 0xbf;
  }
  diag_error(n);
LAB_10637aeb:
  ppcVar9 = local_24->types;
  local_1c = 1;
  if ((int)new_type < 1) {
    return old_type;
  }
  local_20 = 8;
  delta_2 = (int)pcVar8 + (8 - (int)ppcVar9);
  do {
    pcVar5 = *(c1_type **)(delta_2 + (int)ppcVar9);
    if (pcVar5 != *ppcVar9) {
      if (((((recurse == '\0') || (pcVar5->code == 0x80d)) ||
           (bVar4 = type_is_function((byte *)pcVar5), !bVar4)) ||
          (((*ppcVar9)->code == 0x80d || (bVar4 = type_is_function((byte *)*ppcVar9), !bVar4)))) ||
         (pcVar5 = type_compare_function_prototypes
                             (*(c1_type **)(delta_2 + (int)ppcVar9),*ppcVar9,'\0','\x01',
                              pass_through), piVar10 = (int *)g_arenas[3].cur,
         pcVar5 == (c1_type *)0x0)) {
        if (outer == '\0') {
          return (c1_type *)0x0;
        }
        if (g_ms_extensions == '\0') {
          diag_error(0xc0,local_1c);
        }
        else {
          diag_warning(1,0x1c);
        }
      }
      else if (pcVar5 != *ppcVar9) {
        if (local_2c == (c1_symbol *)0x0) {
          g_arenas[3].cur = g_arenas[3].cur + (int)pcVar3 * 4 + 8;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          local_2c = (c1_symbol *)piVar10;
          pcVar8 = local_24;
          for (uVar6 = (int)pcVar3 * 4 + 8U >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            pcVar8->count = *piVar10;
            piVar10 = piVar10 + 1;
            pcVar8 = (c1_param_list *)&pcVar8->debug_index;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(uchar *)&pcVar8->count = (uchar)*piVar10;
            piVar10 = (int *)((int)piVar10 + 1);
            pcVar8 = (c1_param_list *)((int)&pcVar8->count + 1);
          }
        }
        *(c1_type **)(&local_2c->kind + local_20) = pcVar5;
      }
    }
    local_1c = local_1c + 1;
    local_20 = local_20 + 4;
    ppcVar9 = ppcVar9 + 1;
  } while (local_1c <= (int)new_type);
  if (local_2c != (c1_symbol *)0x0) {
    base_words = _outer;
    if (outer == '\0') {
      local_28 = old_type->base;
      base_words = (uint *)(-(uint)((old_type->code & 0x80) != 0) & (uint)old_type);
    }
    if (((local_28->extra).sym != local_2c) &&
       (local_10.extra.sym = (c1_symbol *)type_intern_parameter_list(local_2c),
       (local_28->extra).sym != local_10.extra.sym)) {
      local_10.code = local_28->code;
      local_10.flags = local_28->flags;
      local_10.base = local_28->base;
      local_10.debug_index = local_28->debug_index;
      type_intern(&local_10);
    }
    if (outer != '\0') {
      return local_28;
    }
    local_10._0_4_ = *base_words;
    local_10.extra = *(c1_type_x08 *)(base_words + 2);
    local_10.debug_index = 0;
    local_10.base = local_28;
    pcVar5 = type_intern(&local_10);
    return pcVar5;
  }
  return old_type;
}

