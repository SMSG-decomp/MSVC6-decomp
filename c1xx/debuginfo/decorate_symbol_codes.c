uint __cdecl decorate_symbol_codes(c1_symbol *sym)

{
  c1_u8 cVar1;
  c1_type *pcVar2;
  fe_name *pfVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  
  bVar4 = 0;
  bVar6 = sym->flags1;
  uVar8 = 0;
  if (((((bVar6 & 2) != 0) ||
       ((((pcVar2 = sym->type, pcVar2 != (c1_type *)0x0 && ((pcVar2->code & 0x83) == 0x81)) &&
         (*(int *)(((uint)pcVar2 & -(uint)((pcVar2->code & 0x80) != 0)) + 8) == 0)) &&
        (sym->name != g_name_local_static_destructor)))) ||
      ((((((sym->name->flags & 0x40000000) != 0 && (sym->scope_index == 0)) &&
         (bVar7 = sym->kind & 0x1f, bVar7 != 3)) && (((bVar7 == 7 || (bVar7 == 8)) || (bVar7 == 6)))
        ) && ((sym->storage & 7) != 3)))) || (bVar7 = sym->storage & 7, bVar7 == 7)) {
    return 0;
  }
  bVar5 = sym->kind & 0x1f;
  if (((bVar5 != 7) && (bVar5 != 8)) && (bVar5 != 6)) {
    pfVar3 = sym->name;
    if (pfVar3 == g_name_vftable) {
      return 0xb736;
    }
    if (pfVar3 == g_name_local_vftable) {
      return 0xd336;
    }
    if (pfVar3 == g_name_vbtable) {
      return 0xb837;
    }
    if (pfVar3 == g_name_vdispmap) {
      return 0xcb3a;
    }
    if (bVar5 == 3) {
      if (bVar7 != 3) {
        return 0;
      }
      bVar6 = sym->flags2 & 3;
      if (bVar6 != 2) {
        if (bVar6 != 3) {
          return 0x30;
        }
        return 0x32;
      }
      return 0x31;
    }
    if (pfVar3 != g_name_local_static_guard) {
      if (bVar5 != 10) {
        return 0;
      }
      if ((3 < bVar7) && (bVar7 < 7)) {
        return 0;
      }
    }
    if (bVar7 != 3) {
      return 0x33;
    }
    if ((sym->x28).block_number == 0) {
      return 0;
    }
    if (pfVar3 == g_name_local_static_guard) {
      return 0xc235;
    }
    return 0x34;
  }
  bVar7 = *(byte *)((int)&sym->tail + 9);
  bVar5 = bVar7 & 0xc;
  bVar7 = bVar7 & 0xc;
  if (bVar5 != 0) {
    if (bVar5 == 4) {
      uVar8 = ((bVar7 != 8) - 1 & 0x14) + 6;
    }
    else if (bVar7 == 8) {
      uVar8 = decorate_symbol_codes_member_tail(0,8,bVar6,sym,g_name_local_static_destructor);
      return uVar8;
    }
  }
  if ((bVar6 & 0x10) == 0x10) {
    bVar4 = 0x30;
LAB_1040f8a6:
    if (uVar8 == 0x1a) {
      bVar6 = sym->flags2 & 3;
      if (bVar6 == 2) {
        uVar8 = 0x1c;
      }
      else if (bVar6 == 3) {
        uVar8 = 0x1e;
      }
    }
    else {
      if (uVar8 == 6) {
LAB_1040f8db:
        bVar6 = sym->flags2 & 3;
        if (bVar6 == 2) {
          uVar8 = uVar8 | 8;
        }
        else if (bVar6 == 3) {
          uVar8 = uVar8 | 0x10;
        }
      }
      else if (uVar8 == 0) {
        if ((bVar6 & 4) == 0) {
          uVar8 = 0x18;
          goto LAB_1040f904;
        }
        if ((sym->flags21 & 2) == 0) {
          uVar8 = ((byte)~*(byte *)((int)&sym->tail + 8) & 1) << 1;
        }
        else {
          uVar8 = 4;
        }
        goto LAB_1040f8db;
      }
      if (((uVar8 == 0x24) || (uVar8 == 0x25)) || (uVar8 == 0x26)) goto LAB_1040f913;
      if (uVar8 == 0x39) goto LAB_1040f907;
    }
LAB_1040f904:
    uVar8 = uVar8 + 0x41;
  }
  else {
    if ((bVar6 & 0x20) == 0x20) {
      bVar4 = 0x31;
      goto LAB_1040f8a6;
    }
    if ((bVar6 & 0x40) != 0) {
      bVar4 = 0x42;
      goto LAB_1040f8a6;
    }
    if ((bVar7 == 0) || (bVar7 != 0xc)) {
      pfVar3 = sym->name;
      if (pfVar3 == g_name_default_ctor_closure) {
        bVar4 = 0xc6;
      }
      else if (pfVar3 == g_name_local_vftable_ctor_closure) {
        bVar4 = 0xd4;
      }
      else if (pfVar3 == g_name_copy_ctor_closure) {
        bVar4 = 0xcf;
      }
      else if (pfVar3 == g_name_vector_ctor_iterator) {
        bVar4 = 200;
      }
      else if (pfVar3 == g_name_vector_vbase_ctor_iterator) {
        bVar4 = 0xca;
      }
      else if (pfVar3 == g_name_vector_dtor_iterator) {
        bVar4 = 0xc9;
      }
      else if (pfVar3 == g_name_eh_vector_ctor_iterator) {
        bVar4 = 0xcc;
      }
      else if (pfVar3 == g_name_eh_vector_vbase_ctor_iterator) {
        bVar4 = 0xce;
      }
      else if (pfVar3 == g_name_eh_vector_dtor_iterator) {
        bVar4 = 0xcd;
      }
      else if (pfVar3 == g_name_vbase_dtor) {
        bVar4 = 0xc4;
      }
      else if (pfVar3 == g_name_scalar_deleting_dtor) {
        bVar4 = 199;
      }
      else if (pfVar3 == g_name_vector_deleting_dtor) {
        bVar4 = 0xc5;
      }
      else {
        cVar1 = (sym->tail).fn.op_token;
        if ((cVar1 == '\0') || (cVar1 == '\x01')) {
          if (pfVar3 == g_name_local_static_destructor) {
            return 0x24;
          }
          if (pfVar3 == g_name_template_static_member_ctor) {
            return 0x25;
          }
          if (pfVar3 == g_name_template_static_member_dtor) {
            return 0x26;
          }
        }
        else {
          switch(cVar1) {
          case '1':
            bVar4 = 0x49;
            break;
          case '2':
            bVar4 = 0x56;
            break;
          case '3':
            bVar4 = 0xb4;
            break;
          case '4':
            bVar4 = 0x34;
            break;
          default:
            bVar4 = 0xc0;
            break;
          case '7':
            bVar4 = 0x51;
            break;
          case '8':
          case 'T':
            bVar4 = 0x46;
            break;
          case '9':
            bVar4 = 0x4b;
            break;
          case ':':
            bVar4 = 0xb0;
            break;
          case ';':
            bVar4 = 0x38;
            break;
          case '<':
            bVar4 = 0x37;
            break;
          case '=':
          case 'J':
            bVar4 = 0x44;
            break;
          case '>':
            bVar4 = 0x4f;
            break;
          case '?':
            bVar4 = 0x50;
            break;
          case '@':
          case 'U':
            bVar4 = 0x45;
            break;
          case 'A':
            bVar4 = 0x41;
            break;
          case 'B':
            bVar4 = 0xb3;
            break;
          case 'C':
            bVar4 = 0x36;
            break;
          case 'D':
            bVar4 = 0x4d;
            break;
          case 'E':
            bVar4 = 0x4e;
            break;
          case 'F':
          case 'Z':
            bVar4 = 0x47;
            break;
          case 'G':
            bVar4 = 0x5a;
            break;
          case 'H':
            bVar4 = 0x4c;
            break;
          case 'I':
            bVar4 = 0xb1;
            break;
          case 'K':
            bVar4 = 0x58;
            break;
          case 'L':
            bVar4 = 0x39;
            break;
          case 'M':
            bVar4 = 0x55;
            break;
          case 'N':
            bVar4 = 0xb5;
            break;
          case 'O':
            bVar4 = 0x57;
            break;
          case 'Q':
          case 0x86:
            bVar4 = 0x48;
            break;
          case 'R':
            bVar4 = 0x59;
            break;
          case 'S':
            bVar4 = 0x43;
            break;
          case 'W':
            bVar4 = 0xb2;
            break;
          case 'X':
            bVar4 = 0x35;
            break;
          case 'Y':
            bVar4 = 0x53;
            break;
          case '[':
            bVar4 = 0x54;
            break;
          case '\\':
            bVar4 = 0xb6;
            break;
          case 'v':
            bVar4 = 0x52;
            break;
          case 0x8c:
            bVar4 = ((pfVar3 != g_name_array_new) - 1U & 0xa3) + 0x32;
            break;
          case 0x8d:
            if (pfVar3 == g_name_array_delete) {
              bVar4 = 0xd6;
            }
            else if (pfVar3 == g_name_placement_delete_closure) {
              bVar4 = 0xd8;
            }
            else {
              bVar4 = ((pfVar3 != g_name_placement_array_delete_closure) - 1U & 0xa6) + 0x33;
            }
            break;
          case 0x93:
            bVar4 = 0x4a;
          }
        }
      }
      goto LAB_1040f8a6;
    }
    uVar8 = 0x39;
    bVar4 = 0xb9;
  }
LAB_1040f907:
  if (((sym->flags23 & 1) != 0) && ((uVar8 == 0x39 || ((sym->flags23 & 2) == 0)))) {
    uVar8 = uVar8 | 0x80;
  }
LAB_1040f913:
  if (bVar4 != 0) {
    uVar8 = uVar8 | (uint)bVar4 << 8;
  }
  return uVar8;
}

