vector:
 
c'de malloc ve realloc felan kullanırdık heapde yer açmak için
vector ise arka planda tüm bellek yönetimi yapan dinamik bir dizidir.
bellekte ki elemanları tıpkı normal diziler gibi yan yana tutar

avantajı: içi doldukça kendi kapasitesini otoamatik olarak büyütür.
Herhangi bir elemana (örnek 5.elemana) anında erişebiliriz. 'v[4]'


std::list(çift yönlü bağlı liste):

C'de düğümler (nodes) oluşturup next ve prev işaretçileriyle birbirine bağlayan
yapılar gibi

List c++'nin hazır çift yönlü bağlı listesidir. Bellekte elemanlar yan yana durmaz
Her eleman kendinden bir öncekini ve bir sonrakini işaret eden bağlantılara sahiptir.

avantajı: Araya veya başa/sona eleman ekleyip çıkarmak çok hızlıdır.
Sadece bağlantı koparılıp yapılır. Vektördeki gibi diğer elemanları kaydırmak gerekmez


push_back (sona ekleme):

Bu hem vector hem de list içinde bulunan hazır bir fonksiyondur. Görevi elindeki veriyi
alıp konteynırın en sonuna yeni bir eleman olarak eklemektir.

C'de ki karşılığı: Vektör için dizinin sonuna eleman ekleyip gerekiyorsa realloc yapmasıdır. Liste için ise yazmış olabilecek bir lst_add_back fonksiyonunun tam karşılığı


iterator (Gelişmiş isaretçi / pointer)

STL'nin kalbi burası. C'de bir dizinin üzerinde gezinmek için standart bir pointer
(int *ptr) kullanıp ptr++ derdik. Ancak bağlı listede gezinmek için
current = current->next demek zorundaydık. İki farklı yapı, iki farklı gezinme mantığı
istiyordu.

İterator, farklı konteyner türlerinde aynı kodla gezinmeyi sağlayan akıllı bir nesne!

konteynerın başını işaret etmek için begin() kullanılır.
sonunu (son elemanı değil son elemandan sonra ki boşluğu) işaret etmek için
end() kullanılır.

Bir iterator oluşturup ona it++ denildiğinde; eğer bir vektörün üzerindeysek bellekte
yan tarafa geçer. Eğer listenin üzerindeyse arka planda otomatik olarak current->next
yapar. Biz sadece it++ der geçeriz.

