void __fastcall pch_fixup_list_object(c1xx_obj_104c4c3c *obj)

{
  pch_mark_object_links((int)obj);
  pch_relocate_slot_once(&g_pch_image,(uint *)(obj + 4));
  return;
}

