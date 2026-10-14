ushort __cdecl tmpl_type_find_parameter(c1_type *type,int skip_template_template,int param_id)

{
  c1_symbol *key;
  c1_type_list *pcVar1;
  c1_type *pcVar2;
  byte bVar3;
  int *piVar4;
  ushort uVar5;
  int iVar6;
  c1_type **ppcVar7;
  ushort uVar8;
  
  do {
    while( true ) {
      uVar5 = type->code;
      uVar8 = (ushort)param_id;
      if (-1 < (char)(byte)uVar5) break;
      if (((byte)uVar5 & 0x83) == 0x81) {
        pcVar2 = ((type->extra).params)->this_type;
        if ((pcVar2 != (c1_type *)0x0) &&
           (uVar5 = tmpl_type_find_parameter(pcVar2,skip_template_template,param_id), uVar5 != 0)) {
          if (uVar8 == 0) {
            return uVar5;
          }
          if (uVar8 == uVar5) {
            return uVar5;
          }
        }
        pcVar1 = ((type->extra).params)->list;
        iVar6 = pcVar1->count;
        ppcVar7 = pcVar1->types;
        if (iVar6 < 1) goto LAB_10424f39;
        do {
          uVar5 = tmpl_type_find_parameter(*ppcVar7,skip_template_template,param_id);
          if (uVar5 != 0) {
            if (uVar8 == 0) {
              return uVar5;
            }
            if (uVar8 == uVar5) {
              return uVar5;
            }
          }
          ppcVar7 = ppcVar7 + 1;
          iVar6 = iVar6 + -1;
        } while (0 < iVar6);
        type = type->base;
      }
      else {
        if (((uVar5 & 0x8f) == 0x8a) || ((uVar5 & 0x8f) == 0x8e)) {
          pcVar2 = ((type->extra).cls)->type;
          if (((pcVar2->code & 0x800) != 0) &&
             ((uVar8 == 0 || (uVar8 == *(ushort *)&pcVar2->extra)))) {
            return *(ushort *)&((type->extra).cls)->type->extra;
          }
        }
LAB_10424f39:
        type = type->base;
      }
    }
    if ((uVar5 & 0x200) == 0) goto LAB_10424ee6;
    key = (type->extra).cls;
    bVar3 = ((key->detail).cls)->flags3e;
    if ((bVar3 & 1) != 0) {
      piVar4 = symtab_15f4_lookup(key);
      iVar6 = *piVar4;
      break;
    }
    if ((bVar3 & 2) != 0) {
      return 0xffff;
    }
    if ((key->scope_index == 0) ||
       ((g_scope_vector->entries[(short)key->scope_index]->kind & 0x1f) != 4)) goto LAB_10424ee6;
    type = g_scope_vector->entries[(short)key->scope_index]->type;
  } while( true );
LAB_10482d26:
  bVar3 = *(byte *)(iVar6 + 0xc) & 3;
  if (bVar3 == 0) {
    uVar5 = tmpl_type_find_parameter(*(c1_type **)(iVar6 + 0x10),skip_template_template,param_id);
    if (uVar5 != 0) {
      if (uVar8 == 0) {
        return uVar5;
      }
joined_r0x10482d85:
      if (uVar8 == uVar5) {
        return uVar5;
      }
    }
  }
  else if ((bVar3 == 1) &&
          (uVar5 = tmpl_expression_parameter_id(*(char **)(iVar6 + 0x10),uVar8), uVar5 != 0)) {
    if (uVar8 == 0) {
      return uVar5;
    }
    goto joined_r0x10482d85;
  }
  iVar6 = *(int *)(iVar6 + 4);
  if (iVar6 == 0) {
LAB_10424ee6:
    uVar5 = type->code & 0xfff;
    if ((uVar5 == 0x802) && ((char)skip_template_template == '\0')) {
      uVar5 = tmpl_param_type_id_matches(type,param_id);
      return uVar5;
    }
    if (((-1 < (char)type->code) && (uVar5 == 0x801)) &&
       ((uVar8 == 0 || (uVar8 == *(ushort *)&type->extra)))) {
      return *(ushort *)&type->extra;
    }
    return 0;
  }
  goto LAB_10482d26;
}

