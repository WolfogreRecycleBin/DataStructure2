#include "CrossListNetwork.h"
#include "ShortestPathBellmanFord.h"
#include "CriticalPath.h"
int main()
{
	try
	{
		int infity = DEFAULT_INFINITY;
		int I = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
		//		 A  B  C  D  E  F
		/*A*/	{I, I, I, I, I, I},
		/*B*/	{1, I, 2, I, I, I},
		/*C*/	{3, I, I, 4, I, I},
		/*D*/	{I, I, I, I, 5, I},
		/*E*/	{I, I, I, 6, I, I},
		/*F*/	{I, I, I, I, I, I},
		};
		char e, e1, e2;
		int n = 6, v, v1, v2, w;
		CrossListNetwork<char, int> net(vexs, n);
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++)
				if (m[v][u] != infity)
					net.InsertArc(v, u, m[v][u]);
		char c = 'x';
	    while (c != '0')
		{
            cout << endl << "1. ���������.";
            cout << endl << "2. ��ʾ������.";
            cout << endl << "3. ȡָ�������ֵ.";
            cout << endl << "4. ����ָ�������ֵ.";
            cout << endl << "5. ɾ������.";
            cout << endl << "6. ���붥��.";
            cout << endl << "7. ɾ����.";
            cout << endl << "8. �����.";
            cout << endl << "9. ����ָ���ߵ�Ȩ.";
			cout << endl << "a. �����·��.";
			cout << endl << "b. ��ؼ��.";
		    cout << endl << "0. �˳�";
		    cout << endl << "ѡ����(0~9):";
		    cin >> c;
		    switch (c)
			{
			    case '1':
			        net.Clear();
				    break;
			    case '2':
                    if (net.IsEmpty())
                        cout << "��������Ϊ�ա�" << endl;
                    else 
			            net.Display();
				    break;
			    case '3':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
		            net.GetElem(v, e);
		            cout << "���Ϊ" << v << "�Ķ���Ϊ" << e;
			        break;
			    case '4':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
			        cout << endl << "����" << v <<"�Ŷ����ֵ:";
			        cin >> e;
		            net.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "���뱻ɾ�������ֵ:";
			        cin >> e;
		            net.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "������붥���ֵ:";
			        cin >> e;
		            net.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "�����뱻ɾ���߹�������������ֵ:";
			        cin >> e1 >> e2;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.InsertArc(v1, v2, w);
			        break;
			    case '9':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.SetWeight(v1, v2, w);
			        break;
				case 'a':
				{
			        cout << "ԭ��:" << endl;
					net.Display();
					cout << endl;
					system("PAUSE");
					int n = net.GetVexNum();
					for(int v = 0; v < n; v++)
					{
						int dist[n], path[n];
						ShortestPathBellmanFord(net, v, path, dist);
						DisplayPathAndDist(net, v, path, dist);
						cout << endl;
					}
					system("PAUSE");
					break;
				}
				case 'b':
				{
					char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
					int m[7][7] = {
						{I, 3, 2, 6, I, I, I},
						{I, I, I, 2, 4, I, I},
						{I, I, I, 1, I, 3, I},
						{I, I, I, I, 1, I, I},
						{I, I, I, I, I, I, 3},
						{I, I, I, I, I, I, 4},
						{I, I, I, I, I, I, I}
					};
					int n = 7;

					CrossListNetwork<char, int> net(vexs, n);

					for (int u = 0; u < n; u++)
						for (int v = n-1; v >= 0; v--)
							if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);
					cout << endl;
					cout << "������ؼ��Ҫ��ԭͼ�������л�·��ͼ��ͨ��\n����������һ��û�л�·����ͨ��ʮ������������������ʾ:" << endl;
					net.Display();					// ��ʾ��net
					cout << endl;
					system("PAUSE");				// ���ÿ⺯��system()

					if (CriticalPath(net) == SUCCESS)
						cout << endl << "���ڹؼ��" << endl;
					else
						cout << endl << "�����ڹؼ�� " << endl;
					cout << endl;
				}
       	    }
         }
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}
	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
	return 0;
}
