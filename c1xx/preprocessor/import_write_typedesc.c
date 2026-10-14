void __cdecl
import_write_typedesc(c1_il_buffer *buf,void *typedesc,void *typeinfo,wchar_t *name,int qualify_own)

{
  c1_il_buffer *pcVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  c1_typeattr *in_ECX;
  ushort uVar7;
  wchar_t *name_00;
  bool bVar8;
  c1_typeattr *local_8;
  c1_arraydesc *adesc;
  
  uVar3 = *(ushort *)((int)typedesc + 4) - 2;
  name_00 = name;
  local_8 = in_ECX;
  if (0x1d < uVar3) {
switchD_1049bd30_caseD_d:
    return;
  }
switchD_1049bd30_switchD:
  pcVar1 = buf;
  switch(uVar3) {
  case 0:
    pcVar6 = "short";
    break;
  case 1:
    pcVar6 = "long";
    break;
  case 2:
    pcVar6 = "float";
    break;
  case 3:
    pcVar6 = "double";
    break;
  case 4:
    pcVar6 = "CURRENCY";
    break;
  case 5:
    pcVar6 = "DATE";
    break;
  case 6:
    pcVar6 = "BSTR";
    break;
  case 7:
    pcVar6 = "IDispatch *";
    break;
  case 8:
    pcVar6 = "SCODE";
    break;
  case 9:
    pcVar6 = "VARIANT_BOOL";
    break;
  case 10:
    pcVar6 = "VARIANT";
    break;
  case 0xb:
    pcVar6 = "IUnknown *";
    break;
  case 0xc:
    pcVar6 = "DECIMAL";
    break;
  case 0xd:
    goto switchD_1049bd30_caseD_d;
  case 0xe:
    pcVar6 = "char";
    break;
  case 0xf:
    pcVar6 = "unsigned char";
    break;
  case 0x10:
    pcVar6 = "unsigned short";
    break;
  case 0x11:
    pcVar6 = "unsigned long";
    break;
  case 0x12:
    pcVar6 = "__int64";
    break;
  case 0x13:
    pcVar6 = "unsigned __int64";
    break;
  case 0x14:
    pcVar6 = "int";
    break;
  case 0x15:
    pcVar6 = "unsigned int";
    break;
  case 0x16:
    pcVar6 = "void";
    break;
  case 0x17:
    pcVar6 = "HRESULT";
    break;
  case 0x18:
    goto switchD_1049bd30_caseD_18;
  case 0x19:
    pcVar6 = "SAFEARRAY *";
    break;
  case 0x1a:
    adesc = *(c1_arraydesc **)typedesc;
    import_write_typedesc(buf,adesc,typeinfo,name_00,0);
    uVar7 = 0;
    if (adesc->cDims == 0) {
      return;
    }
    do {
      import_text_putc(pcVar1,0x5b);
      import_text_printf(pcVar1,"%lu",adesc->rgbounds[uVar7].cElements);
      import_text_putc(pcVar1,0x5d);
      uVar7 = uVar7 + 1;
    } while (uVar7 < adesc->cDims);
    return;
  case 0x1b:
    bVar2 = import_get_ref_type_info(typeinfo,*(uint *)typedesc,&typedesc);
    if (bVar2 == 0) {
      import_text_puts(buf,"__missing_type__");
      return;
    }
    iVar4 = (**(code **)(*(int *)typedesc + 0x30))(typedesc,0xffffffff,&typeinfo,0,0,0);
    if (iVar4 < 0) {
      diag_fatal_file(iVar4,0x54,0x166,g_import_file_as_written);
    }
    iVar4 = (**(code **)(*(int *)typedesc + 0xc))(typedesc,&name);
    if (iVar4 < 0) {
      diag_fatal_file(iVar4,0x54,0x166,g_import_file_as_written);
    }
    pcVar1 = buf;
    switch(*(undefined4 *)(name + 0x14)) {
    case 0:
      pcVar6 = "enum ";
      goto LAB_1049bfd8;
    case 1:
      iVar4 = wcscmp(typeinfo,L"GUID");
      if (iVar4 == 0) goto switchD_1049bfcc_caseD_2;
      break;
    default:
      goto switchD_1049bfcc_caseD_2;
    case 3:
    case 4:
      break;
    case 5:
      bVar8 = import_coclass_default_interface(typedesc,name,(c1_itypeinfo **)&buf,&local_8);
      if (bVar8) {
        (**(code **)(*(int *)typedesc + 0x4c))(typedesc,name);
        (**(code **)(*(int *)typedesc + 8))(typedesc);
        typedesc = buf;
        name = (wchar_t *)local_8;
        SysFreeString(typeinfo);
        iVar4 = (**(code **)(*(int *)typedesc + 0x30))(typedesc,0xffffffff,&typeinfo,0,0,0);
        if (iVar4 < 0) {
          diag_fatal_file(iVar4,0x54,0x166,g_import_file_as_written);
        }
      }
      break;
    case 7:
      pcVar6 = "union ";
      goto LAB_1049bfd8;
    }
    pcVar6 = "struct ";
LAB_1049bfd8:
    import_text_puts(pcVar1,pcVar6);
switchD_1049bfcc_caseD_2:
    (**(code **)(*(int *)typedesc + 0x4c))(typedesc,name);
    pwVar5 = import_namespace_for_typeinfo(typedesc,(char)qualify_own);
    if (pwVar5 != (wchar_t *)0x0) {
      import_text_printf(pcVar1,"%S::",pwVar5);
    }
    pwVar5 = import_apply_rename(typeinfo);
    import_text_printf(pcVar1,"%S",pwVar5);
    if (name_00 != (wchar_t *)0x0) {
      import_text_printf(pcVar1," %S",name_00);
    }
    SysFreeString(typeinfo);
    (**(code **)(*(int *)typedesc + 8))(typedesc);
    return;
  case 0x1c:
    pcVar6 = "LPSTR";
    break;
  case 0x1d:
    pcVar6 = "LPWSTR";
  }
  import_text_puts(buf,pcVar6);
  if (name_00 == (wchar_t *)0x0) {
    return;
  }
  import_text_printf(pcVar1," %S",name_00);
  return;
switchD_1049bd30_caseD_18:
  bVar8 = *(short *)(*(int *)typedesc + 4) == 0x1c;
  if (name_00 == (wchar_t *)0x0) {
    name_00 = L"(*)";
    if (!bVar8) {
      name_00 = L"*";
    }
  }
  else {
    wcslen(name_00);
    pwVar5 = L"(* ";
    if (!bVar8) {
      pwVar5 = L"* ";
    }
    wcscpy((wchar_t *)&stack0xffffffec,pwVar5);
    wcscat((wchar_t *)&stack0xffffffec,name_00);
    name_00 = (wchar_t *)&stack0xffffffec;
    if (bVar8) {
      wcscat((wchar_t *)&stack0xffffffec,L")");
      name_00 = (wchar_t *)&stack0xffffffec;
    }
  }
  qualify_own = qualify_own & 0xffffff00;
  typedesc = *(void **)typedesc;
  uVar3 = *(ushort *)((int)typedesc + 4) - 2;
  if (0x1d < uVar3) {
    return;
  }
  goto switchD_1049bd30_switchD;
}

