void __cdecl pch_relocate_template_argument_list(uint *slot)

{
  undefined4 *puVar1;
  
  pch_relocate_slot_once(&g_pch_image,slot);
  pch_relocate_slot_once(&g_pch_image,slot + 1);
  for (puVar1 = (undefined4 *)*slot; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[1])
  {
    (**(code **)*puVar1)();
  }
  return;
}

