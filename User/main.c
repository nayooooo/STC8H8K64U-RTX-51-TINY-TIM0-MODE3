#include "RTX51TNY.h"

#include "main.h"

/*******************************************************************************
* �� �� ��       : main_task
* ��������		 : ����0
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void Main_Task(void) _task_ MAIN_TASK
{
	EA_CLS;
	
	CreatTask:
	if(os_create_task(LED_FLASH_TASK))
	{
		goto CreatTask;
	}
	DeleteTask:
	if(os_delete_task(MAIN_TASK))
	{
		goto DeleteTask;
	}
	
	EA_OPN;
	
	while(1)
	{
		;
	}
}

/*******************************************************************************
* �� �� ��       : LED_Flash
* ��������		 : ����1
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void LED_Flash(void) _task_ LED_FLASH_TASK
{
	u8 i = 0;  // ʵ�����ʱʱ��ԼΪ255��ʱ��Ƭ
			   // Ӧ����ʹ����8λ���ȵı������������޸�
	LED_Init();
	
	while(1)
	{
		os_wait(K_IVL, i, 0);
		
		LED(0) = !LED(0);
		i++;
	}
}