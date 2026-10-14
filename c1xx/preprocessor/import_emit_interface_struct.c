void __cdecl import_emit_interface_struct(void *typeinfo,void *typeattr,wchar_t *name)

{
  void *typeinfo_00;
  void *pvVar1;
  wchar_t *class_name;
  byte bVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint next_vft_offset;
  int iVar5;
  uint local_58;
  byte text_buffers_a [24];
  byte text_buffers_b [24];
  int *piStack_c;
  
  next_vft_offset = 0;
  import_text_puts(g_import_items,"\nstruct __declspec(uuid(\"");
  pvVar1 = typeattr;
  import_write_guid_string(g_import_items,typeattr);
  class_name = name;
  import_text_printf(g_import_items,"\"))\n%S",name);
  typeinfo_00 = typeinfo;
  if (*(short *)((int)pvVar1 + 0x30) != 0) {
    import_text_puts(g_import_items," : ");
    iVar3 = (**(code **)(*(int *)typeinfo_00 + 0x20))(typeinfo_00,0);
    if (iVar3 < 0) {
      diag_fatal_file(iVar3,0x54,0x166,g_import_file_as_written);
    }
    bVar2 = import_get_ref_type_info(typeinfo_00,local_58,&name);
    if (bVar2 == 0) {
      import_text_puts(g_import_items,"__missing_type__");
      next_vft_offset = 0xffffffff;
    }
    else {
      pwVar4 = import_namespace_for_typeinfo((int *)name,'\0');
      if (pwVar4 != (wchar_t *)0x0) {
        import_text_printf(g_import_items,"%S::");
      }
      iVar5 = 0;
      iVar3 = (**(code **)(*(int *)name + 0x30))(name,0xffffffff,&typeinfo,0,0);
      if (iVar3 < 0) {
        diag_fatal_file(iVar3,0x54,0x166,g_import_file_as_written);
      }
      pwVar4 = import_apply_rename((wchar_t *)text_buffers_b._20_4_);
      import_text_printf(g_import_items,"%S",pwVar4);
      iVar3 = (**(code **)(*piStack_c + 0xc))(piStack_c,&stack0xffffff94);
      if (iVar3 < 0) {
        diag_fatal_file(iVar3,0x54,0x166,g_import_file_as_written);
      }
      next_vft_offset = (uint)*(ushort *)(iVar5 + 0x32);
      (**(code **)(*(int *)text_buffers_b._20_4_ + 0x4c))(text_buffers_b._20_4_,iVar5);
      SysFreeString((wchar_t *)text_buffers_b._4_4_);
      (**(code **)(*(int *)text_buffers_b._12_4_ + 8))(text_buffers_b._12_4_);
    }
  }
  import_text_puts(g_import_items,"\n{");
  pvVar1 = typeattr;
  g_import_member_wrappers = (c1_il_buffer *)text_buffers_a;
  g_import_member_raw_methods = (c1_il_buffer *)(text_buffers_b + 0x14);
  g_import_member_property_data = (c1_il_buffer *)text_buffers_b;
  g_import_member_implementations = (c1_il_buffer *)(text_buffers_a + 0x14);
  text_buffers_a[0] = 0;
  text_buffers_a[1] = 0;
  text_buffers_a[2] = 0;
  text_buffers_a[3] = 0;
  text_buffers_a[4] = 0;
  text_buffers_a[5] = 0;
  text_buffers_a[6] = 0;
  text_buffers_a[7] = 0;
  text_buffers_a[8] = 0;
  text_buffers_a[9] = 0;
  text_buffers_a[10] = 0;
  text_buffers_a[0xb] = 0;
  text_buffers_a[0xc] = 0;
  text_buffers_a[0xd] = 0;
  text_buffers_a[0xe] = 0;
  text_buffers_a[0xf] = 0;
  text_buffers_a[0x10] = 0;
  text_buffers_a[0x11] = 0;
  text_buffers_a[0x12] = 0;
  text_buffers_a[0x13] = 0;
  text_buffers_b[0x14] = 0;
  text_buffers_b[0x15] = 0;
  text_buffers_b[0x16] = 0;
  text_buffers_b[0x17] = 0;
  text_buffers_b[0] = 0;
  text_buffers_b[1] = 0;
  text_buffers_b[2] = 0;
  text_buffers_b[3] = 0;
  text_buffers_b[4] = 0;
  text_buffers_b[5] = 0;
  text_buffers_b[6] = 0;
  text_buffers_b[7] = 0;
  text_buffers_b[8] = 0;
  text_buffers_b[9] = 0;
  text_buffers_b[10] = 0;
  text_buffers_b[0xb] = 0;
  text_buffers_b[0xc] = 0;
  text_buffers_b[0xd] = 0;
  text_buffers_b[0xe] = 0;
  text_buffers_b[0xf] = 0;
  text_buffers_b[0x10] = 0;
  text_buffers_b[0x11] = 0;
  text_buffers_b[0x12] = 0;
  text_buffers_b[0x13] = 0;
  text_buffers_a[0x14] = 0;
  text_buffers_a[0x15] = 0;
  text_buffers_a[0x16] = 0;
  text_buffers_a[0x17] = 0;
  import_emit_functions(typeinfo_00,typeattr,class_name,next_vft_offset);
  if ((text_buffers_b._4_4_ != text_buffers_b._0_4_) ||
     (text_buffers_a._4_4_ != text_buffers_a._0_4_)) {
    if (text_buffers_b._4_4_ != text_buffers_b._0_4_) {
      import_text_puts(g_import_items,"\n    //\n    // Property data\n    //\n\n");
      import_text_append((c1_il_buffer *)text_buffers_b,g_import_items);
    }
    if (text_buffers_a._4_4_ != text_buffers_a._0_4_) {
      import_text_puts(g_import_items,
                       "\n    //\n    // Wrapper methods for error-handling\n    //\n\n");
      import_text_append((c1_il_buffer *)text_buffers_a,g_import_items);
    }
  }
  if (text_buffers_b._20_4_ != 0) {
    import_text_puts(g_import_items,"\n    //\n    // Raw methods provided by interface\n    //\n\n"
                    );
    import_text_append((c1_il_buffer *)(text_buffers_b + 0x14),g_import_items);
  }
  if (text_buffers_a._20_4_ != 0) {
    import_text_printf(g_import_tli_implementations,
                       "\n//\n// interface %S wrapper method implementations\n//\n");
    import_text_append((c1_il_buffer *)(text_buffers_a + 0x14),g_import_tli_implementations);
  }
  import_text_puts(g_import_items,"};\n");
  import_write_named_guid(pvVar1,"I",class_name);
  import_text_printf(g_import_smartptr_typedefs,"_COM_SMARTPTR_TYPEDEF(%S, __uuidof(%S));\n",
                     class_name,class_name);
  if (text_buffers_a._20_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_a._20_4_);
  }
  if (text_buffers_b._0_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_b._0_4_);
    text_buffers_b[8] = 0;
    text_buffers_b[9] = 0;
    text_buffers_b[10] = 0;
    text_buffers_b[0xb] = 0;
  }
  if (text_buffers_b._20_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_b._20_4_);
  }
  if (text_buffers_a._0_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_a._0_4_);
  }
  return;
}

