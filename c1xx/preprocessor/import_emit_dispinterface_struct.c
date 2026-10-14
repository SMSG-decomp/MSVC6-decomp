void __cdecl import_emit_dispinterface_struct(void *typeinfo,void *typeattr,wchar_t *name)

{
  char *pcVar1;
  byte text_buffers_a [24];
  byte text_buffers_b [24];
  
  import_text_puts(g_import_items,"\nstruct __declspec(uuid(\"");
  import_write_guid_string(g_import_items,typeattr);
  import_text_printf(g_import_items,"\"))\n%S : IDispatch\n{",name);
  g_import_member_wrappers = (c1_il_buffer *)(text_buffers_b + 0x14);
  g_import_member_raw_methods = (c1_il_buffer *)text_buffers_a;
  g_import_member_property_data = (c1_il_buffer *)text_buffers_b;
  g_import_member_implementations = (c1_il_buffer *)(text_buffers_a + 0x14);
  text_buffers_b[0x14] = 0;
  text_buffers_b[0x15] = 0;
  text_buffers_b[0x16] = 0;
  text_buffers_b[0x17] = 0;
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
  if (*(short *)((int)typeattr + 0x2c) != 0) {
    if (g_import_raw_interfaces_only == 0) {
      import_text_puts((c1_il_buffer *)(text_buffers_b + 0x14),"\n    // Methods:\n");
    }
    if (g_import_raw_dispinterfaces != 0) {
      import_text_puts((c1_il_buffer *)text_buffers_a,"\n    // Methods:\n");
    }
  }
  import_emit_functions(typeinfo,typeattr,name,-1);
  if (*(short *)((int)typeattr + 0x2e) != 0) {
    if (g_import_raw_interfaces_only == 0) {
      import_text_puts((c1_il_buffer *)(text_buffers_b + 0x14),"\n    // Properties:\n");
    }
    if (g_import_raw_dispinterfaces != 0) {
      import_text_puts((c1_il_buffer *)text_buffers_a,"\n    // Properties:\n");
    }
  }
  import_emit_record_fields(typeinfo,typeattr,name);
  if (text_buffers_b._4_4_ != text_buffers_b._0_4_) {
    import_text_puts(g_import_items,"\n    //\n    // Property data\n    //\n\n");
    import_text_append((c1_il_buffer *)text_buffers_b,g_import_items);
  }
  if (text_buffers_b._20_4_ != 0) {
    import_text_puts(g_import_items,"\n    //\n    // Wrapper methods for error-handling\n    //\n")
    ;
    import_text_append((c1_il_buffer *)(text_buffers_b + 0x14),g_import_items);
  }
  if (text_buffers_a._4_4_ != text_buffers_a._0_4_) {
    pcVar1 = "";
    if (g_import_raw_interfaces_only == 0) {
      pcVar1 = " without error-handling";
    }
    import_text_printf(g_import_items,"\n    //\n    // Wrapper methods%s\n    //\n",pcVar1);
    import_text_append((c1_il_buffer *)text_buffers_a,g_import_items);
  }
  if (text_buffers_a._20_4_ != 0) {
    import_text_printf(g_import_tli_implementations,
                       "\n//\n// dispinterface %S wrapper method implementations\n//\n",name);
    import_text_append((c1_il_buffer *)(text_buffers_a + 0x14),g_import_tli_implementations);
  }
  import_text_puts(g_import_items,"};\n");
  import_write_named_guid(typeattr,"DI",name);
  import_text_printf(g_import_smartptr_typedefs,"_COM_SMARTPTR_TYPEDEF(%S, __uuidof(IDispatch));\n",
                     name);
  if (text_buffers_a._20_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_a._20_4_);
    il_buffer_set_memory((c1_byte_buffer *)(text_buffers_a + 0x14),(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  if (text_buffers_b._0_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_b._0_4_);
    il_buffer_set_memory((c1_byte_buffer *)text_buffers_b,(c1_u8 *)0x0,(c1_u8 *)0x0);
    text_buffers_b[8] = 0;
    text_buffers_b[9] = 0;
    text_buffers_b[10] = 0;
    text_buffers_b[0xb] = 0;
  }
  if (text_buffers_a._0_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_a._0_4_);
    text_buffers_a[8] = 0;
    text_buffers_a[9] = 0;
    text_buffers_a[10] = 0;
    text_buffers_a[0xb] = 0;
  }
  if (text_buffers_b._20_4_ != 0) {
    __3_YAXPAX_Z((void *)text_buffers_b._20_4_);
  }
  return;
}

